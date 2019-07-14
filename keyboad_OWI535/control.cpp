#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>

#include <libusb-1.0/libusb.h>

#define EP_INTR	(1 | LIBUSB_ENDPOINT_IN)

#define ARM_VENDOR       0x1267
#define ARM_PRODUCT      0x0001
#define CMD_DATALEN      3

#include <string>
#include <iostream>

libusb_device * find_arm(libusb_device **devs)
{
    libusb_device *dev;
    int i = 0;

    while ((dev = devs[i++]) != NULL) {
        struct libusb_device_descriptor desc;
        int r = libusb_get_device_descriptor(dev, &desc);
        if (r < 0) {
            fprintf(stderr, "failed to get device descriptor");
            return NULL;
        }
        if(desc.idVendor == ARM_VENDOR &&
                desc.idProduct == ARM_PRODUCT)
        {
            return dev;
        }
    }
    return NULL;
}

int mainx(unsigned char cmd[3])
{


    libusb_device **devs;
    libusb_device *dev;
    struct libusb_device_handle *devh = NULL;
    int r;
    ssize_t cnt;

    r = libusb_init(NULL);
    if (r < 0)
    {
        fprintf(stderr, "failed to initialize libusb\n");
        return r;
    }

    libusb_set_debug(NULL,2);

    cnt = libusb_get_device_list(NULL, &devs);
    if (cnt < 0)
        return (int) cnt;



    dev=find_arm(devs);
    if(!dev)
    {
        fprintf(stderr, "Robot Arm not found\n");
        return -1;
    }

    r = libusb_open(dev,&devh);
    if(r!=0)
    {
        fprintf(stderr, "Error opening device\n");
        libusb_free_device_list(devs, 1);
        libusb_exit(NULL);
        return -1;
    }


    //    fprintf(stderr, "Sending %02X %02X %02X\n",
    //            (int)cmd[0],
    //            (int)cmd[1],
    //            (int)cmd[2]
    //    );





    r = libusb_control_transfer(devh,
                                0x40, //uint8_t 	bmRequestType,
                                6, //uint8_t 	bRequest,
                                0x100, //uint16_t 	wValue,
                                0,//uint16_t 	wIndex,
                                cmd,
                                CMD_DATALEN,
                                0
                                );

    if(!(r == CMD_DATALEN))
    {
        fprintf(stderr, "Write err. len=%d\n",r);
    }




    libusb_close(devh);
    libusb_free_device_list(devs, 1);
    libusb_exit(NULL);

    //    fprintf(stderr, "Done\n");
    //        return 0;
}





bool deviceExist()
{
    libusb_device **devs;
    libusb_device *dev;

    int r;
    ssize_t cnt;


    r = libusb_init(NULL);
    if (r < 0) return false;

    libusb_set_debug(NULL,2);
    cnt = libusb_get_device_list(NULL, &devs);

    if (cnt < 0)
        return false;

    dev=find_arm(devs);

    if(!dev) {
        libusb_free_device_list(devs, 1);
        libusb_exit(NULL);
        return false;
    }


    libusb_free_device_list(devs, 1);
    libusb_exit(NULL);


    return true;
}




void excute(std::string command)
{
    if(!deviceExist()) return;

    std::string b0 = "00";
    std::string b1 = "00";
    std::string b2 = "01";

    b0 = command.substr(0,2);
    b1 = command.substr(3,5);
    b2 = command.substr(6,8);



    unsigned char cmd[3];
    cmd[0]=(unsigned char)strtol(b0.c_str(),NULL,16);
    cmd[1]=(unsigned char)strtol(b1.c_str(),NULL,16);
    cmd[2]=(unsigned char)strtol(b2.c_str(),NULL,16);

    mainx(cmd);
}


