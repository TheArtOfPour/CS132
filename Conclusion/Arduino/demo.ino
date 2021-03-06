// This example writes a MIFARE memory block 0x08. It is tested with a new MIFARE 1K cards. Uses default keys.
// Note: Memory block 0 is readonly and contains manufacturer data. Do not write to Sector Trailer block
// unless you know what you are doing. Otherwise, the MIFARE card may be unusable in the future.

//Contributed by Seeed Technology Inc (www.seeedstudio.com)

#include <PN532.h>
#include <SPI.h>
#include <Streaming.h>
#include <IRSendRev.h>

/*Chip select pin can be connected to D10 or D9 which is hareware optional*/
/*if you the version of NFC Shield from SeeedStudio is v2.0.*/

#define PN532_CS    9
#define PINBUZZER   A0

PN532 nfc(PN532_CS);


unsigned char dta_ir[] = {9, 90, 91, 11, 31, 4, 0, 0, 0, 0};

int numInput = 0;

//#define  NFC_DEMO_DEBUG 0

void beep()
{
    digitalWrite(PINBUZZER, HIGH);
    delay(100);
    digitalWrite(PINBUZZER, LOW);
}

void nfc_init()
{

    nfc.begin();

    uint32_t versiondata = nfc.getFirmwareVersion();
    if (! versiondata) {
#ifdef NFC_DEMO_DEBUG
        Serial.print("Didn't find PN53x board");
#endif
        while (1); // halt
    }
#ifdef NFC_DEMO_DEBUG
    // Got ok data, print it out!
    Serial.print("Found chip PN5");
    Serial.println((versiondata>>24) & 0xFF, HEX);
    Serial.print("Firmware ver. ");
    Serial.print((versiondata>>16) & 0xFF, DEC);
    Serial.print('.');
    Serial.println((versiondata>>8) & 0xFF, DEC);
    Serial.print("Supports ");
    Serial.println(versiondata & 0xFF, HEX);
#endif
    // configure board to read RFID tags and cards
    nfc.SAMConfig();
}

void setup(void)
{
    Serial.begin(115200);
    pinMode(PINBUZZER, OUTPUT);

#ifdef NFC_DEMO_DEBUG
    Serial.println("Hello world!");
#endif
    nfc_init();
}

void loop(void)
{
    uint32_t id;
    // look for MiFare type cards
    id = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A);

    if (id != 0)
    {
#ifdef NFC_DEMO_DEBUG
        Serial.print("Read card #");
        Serial.println(id);
        Serial.println();
#endif
        uint8_t keys[]= {
        0xFF,0xFF,0xFF,0xFF,0xFF,0xFF    };
        uint8_t writeBuffer[16];
        for(uint8_t i = 0;i < 16;i ++)
        {
            writeBuffer[i]=i; //Fill buffer with 0,1,2....F
        }

        if(nfc.authenticateBlock(1, id ,0x08,KEY_A,keys)) //authenticate block 0x08
        {
            //if authentication successful

            uint8_t block[16];
            //read memory block 0x08
            if(nfc.readMemoryBlock(1,0x08,block))
            {

#ifdef NFC_DEMO_DEBUG
                Serial.println("Read block 0x08:");
                //if read operation is successful
                for(uint8_t i=0;i<16;i++)
                {
                    //print memory block
                    Serial.write(block[i]);
                    Serial.print(" ");
                }
                Serial.println();
#endif
                proc_ir(block[0]);
            }

            while(1)
            {
                if(nfc.readMemoryBlock(1, 0x08, block))
                {
                    delay(20);
                }
                else
                {
                    cout << "available again" << endl;
                    break;
                }
            }
        }

    }

}


void set_speed(unsigned char speedLeft, unsigned char speedRight)
{
    dta_ir[6] = speedLeft;
    dta_ir[7] = dta_ir[6];

    dta_ir[8] = speedRight;
    dta_ir[9] = dta_ir[8];

    IR.Send(dta_ir, 38);
}

void proc_ir(unsigned char dta)
{
    cout << "get in proc_ir" << endl;

    cout << "get ";
    Serial.write(dta);
    cout << endl;

    beep();

    switch(dta)
    {
        case '1':                       // go ahead

        if(numInput>0)
        {
            goAhead(numInput);
            numInput = 0;
        }


        break;

        case '2':                       // turn left

        if(numInput>0)
        {
            turnLeft(numInput);
            numInput = 0;
        }

        break;

        case '3':                       // turn right
        if(numInput > 0)
        {
            turnRight(numInput);
            numInput = 0;
        }
        break;

        case '4':

        if(numInput > 0)
        {
            goBack(numInput);
            numInput = 0;
        }

        case 'A':

        numInput += 10;
        cout << "numInput = " << numInput << endl;
        break;

        case 'B':
        numInput +=20;
        cout << "numInput = " << numInput << endl;


        break;

        case 'C':
        numInput += 40;
        cout << "numInput = " << numInput << endl;

        break;

        case 'D':
        numInput += 80;
        cout << "numInput = " << numInput << endl;

        break;

        case 'E':
        numInput += random(0, 10);
        cout << "numInput = " << numInput << endl;

        break;

        case 'F':
        numInput += random(1,100);
        cout << "numInput = " << numInput << endl;

        break;

        case 'G':
        numInput += random(50, 100);
        cout << "numInput = " << numInput << endl;

        break;
        
        case 'H':
        numInput += random(100, 200);
        cout << "numInput = " << numInput << endl;

        break;



        default:

        break;


    }
}

void turnLeft(int ang)
{
    set_speed(-30, 30);
    ang = ang*3.7;
    delay(ang);
    set_speed(0, 0);
}

void turnRight(int ang)
{
    set_speed(30, -30);
    ang = ang*3.7;
    delay(ang);
    set_speed(0, 0);

}

void goAhead(int dist)
{
    set_speed(60, 60);
    dist *= 31;
    delay(dist);
    set_speed(-40, -40);
    delay(5);
    set_speed(0, 0);
}

void goBack(int dist)
{
    set_speed(-60, -60);
    dist *= 31;
    delay(dist);
    set_speed(40, 40);
    delay(5);
    set_speed(0, 0);
}
