#ifndef GRABBER_H
#define GRABBER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>             /* getopt_long() */
#include <fcntl.h>              /* low-level i/o */
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <asm/types.h>          /* for videodev2.h */
#include <linux/videodev2.h>
#include "../src/cc_image.h"
#include <iostream>
#define CLEAR(x) memset (&(x), 0, sizeof (x))
#define GRABBER_ERROR(x) cerr << ("Error at function "+string(__PRETTY_FUNCTION__)+": "+string(x))
#define MABESA_ERROR(x) cerr << ("Error at function "+string(__PRETTY_FUNCTION__)+": "+string(x))

using namespace std;

struct sbuffer {
        void *start;
        size_t length;
};

#include <string>
#include <math.h>

int xioctl (int fd, int request, void *arg);
sbuffer *init_mmap (int * fd, char * dev_name, int * n_buffers);
void open_device (int * fd, char * dev_name);
void set_standard(int * fd, int dev_standard);
sbuffer *init_device (int * fd, char * dev_name, int width, int height, int * n_buffers, int pixel_format);
void start_capturing (int * fd, int * n_buffers);
void stop_capturing (int * fd);
int abrir_video(string standard, string deviceName);
int yuv2rgb(int y, int u, int v, char *r, char *g, char *b);
void process2(unsigned int *start, int w, int h);
void process2a(unsigned int *start, int w, int h);
int read_frame();

#endif // #ifndef GRABBER_H
