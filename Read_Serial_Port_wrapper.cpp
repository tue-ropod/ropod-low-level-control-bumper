
/*
 * Include Files
 *
 */
#include "simstruc.h"



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
int fd[3];
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start functions
 *
 */
void Read_Serial_Port_Start_wrapper(SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
//initialisation
int portNr, i, bytes_avail;
  char port[20];
  struct termios toptions;

  for(i = 0; i < 4; i++){ //for port 0 to 3
    /* open serial port */  
    portNr = i;  
    sprintf(port, "/dev/ttyACM%d", portNr);
    fd[i] = open(port, O_RDWR | O_NOCTTY);      
    if(fd[i] == -1){	/* Error Checking */
        printf("Error! in Opening %s \n", port);
        return;
    }
    else{
        printf("%s opened successfully \n", port);
        printf("fd opened as %i\n", fd[i]);
    }  
    /* wait for the Arduino to reboot */
//    usleep(50000);
    /* get current serial port settings */
    tcgetattr(fd[i], &toptions);
    /* set 9600 baud both ways */
    cfsetispeed(&toptions, B115200);
    cfsetospeed(&toptions, B115200);
    /* 8 bits, no parity, no stop bits */
    toptions.c_cflag &= ~PARENB; /* Disables the Parity Enable bit(PARENB),So No Parity   */
    toptions.c_cflag &= ~CSTOPB; /* CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit */
    toptions.c_cflag &= ~CSIZE;  /* Clears the mask for setting the data size             */
    toptions.c_cflag |= CS8;     /* Set the data bits = 8                                 */
    toptions.c_cflag &= ~HUPCL;
    /* Canonical mode */
    toptions.c_lflag |= ICANON;
    /* commit the serial port settings */
    tcsetattr(fd[i], TCSANOW, &toptions);
    /* check bytes available */
//    ioctl(fd[i], FIONREAD, &bytes_avail);
//    if (bytes_avail > 0){
//       printf("Initialisation ACM%i done \n",i);   
//    }
//    else
//       printf("\n Error! ACM%i \n \n",i);
    }
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output functions
 *
 */
void Read_Serial_Port_Outputs_wrapper(real_T *dxp1,
			real_T *dxp2,
			real_T *dxp3,
			real_T *dxp4,
			real_T *sxp1,
			real_T *sxp2,
			real_T *sxp3,
			real_T *sxp4,
			real_T *dxm1,
			real_T *dxm2,
			real_T *dxm3,
			real_T *dxm4,
			real_T *sxm1,
			real_T *sxm2,
			real_T *sxm3,
			real_T *sxm4,
			real_T *dyp1,
			real_T *dyp2,
			real_T *dyp3,
			real_T *dyp4,
			real_T *syp1,
			real_T *syp2,
			real_T *syp3,
			real_T *syp4,
			real_T *dym1,
			real_T *dym2,
			real_T *dym3,
			real_T *dym4,
			real_T *sym1,
			real_T *sym2,
			real_T *sym3,
			real_T *sym4,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
//READPORT   
    int j, n, bytes_avail, number;
    float data[7];
    char buf[64];
    for(j = 0; j < 4; j++){ 
     /* check bytes available */
     ioctl(fd[j], FIONREAD, &bytes_avail);
     if (bytes_avail > 0) {
        /* Receive string from Arduino */
        n = read(fd[j], buf, 64);
        /* insert terminating zero in the string */
        buf[n] = 0;
        //printf("%i bytes read at port %d, fd number %i, buffer contains: %s", n, j, fd[j], buf);
        sscanf(buf, "%i %f %f %f %f %f %f %f %f", &number, &data[0], &data[1], &data[2], &data[3], &data[4], &data[5], &data[6], &data[7]);
        if (number == 1) { 
           dxp2[0] = data[0]/1000.0; //mm->m
           dxp1[0] = data[1]/1000.0; //mm->m
           dyp4[0] = data[2]/1000.0; //mm->m
           dyp3[0] = data[3]/1000.0; //mm->m
           sxp2[0] = data[4]/100.0; //%->m/s
           sxp1[0] = data[5]/100.0; //%->m/s
           syp4[0] = data[6]/100.0; //%->m/s
           syp3[0] = data[7]/100.0; //%->m/s
        }
        else if (number == 2) { 
           dxm3[0] = data[0]/1000.0; //mm->m
           dxm4[0] = data[1]/1000.0; //mm->m
           dyp1[0] = data[2]/1000.0; //mm->m
           dyp2[0] = data[3]/1000.0; //mm->m
           sxm3[0] = data[4]/100.0; //%->m/s
           sxm4[0] = data[5]/100.0; //%->m/s
           syp1[0] = data[6]/100.0; //%->m/s
           syp2[0] = data[7]/100.0; //%->m/s
        }
        else if (number == 3) { 
           dxp3[0] = data[0]/1000.0; //mm->m
           dxp4[0] = data[1]/1000.0; //mm->m
           dym1[0] = data[2]/1000.0; //mm->m
           dym2[0] = data[3]/1000.0; //mm->m
           sxp3[0] = data[4]/100.0;  //%->m/s
           sxp4[0] = data[5]/100.0;  //%->m/s
           sym1[0] = data[6]/100.0;  //%->m/s
           sym2[0] = data[7]/100.0;  //%->m/s
        }
        else if (number == 4) { 
           dxm2[0] = data[0]/1000.0; //mm->m
           dxm1[0] = data[1]/1000.0; //mm->m
           dym4[0] = data[2]/1000.0; //mm->m
           dym3[0] = data[3]/1000.0; //mm->m
           sxm2[0] = data[4]/100.0;  //%->m/s
           sxm1[0] = data[5]/100.0;  //%->m/s
           sym4[0] = data[6]/100.0;  //%->m/s
           sym3[0] = data[7]/100.0;  //%->m/s
       }
     }
  }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Terminate functions
 *
 */
void Read_Serial_Port_Terminate_wrapper(SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
// CLOSEPORT
  close(fd[0]); /* Close the serial port */
  printf("ACM0 closed\n");
  close(fd[1]); /* Close the serial port */
  printf("ACM1 closed\n");
  close(fd[2]); /* Close the serial port */
  printf("ACM2 closed\n");
  close(fd[3]); /* Close the serial port */
  printf("ACM3 closed\n");
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}

