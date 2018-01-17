#CXX = arm-none-linux-gnueabi-g++
CXX = g++

CFLAGS = -Wall -O2

INCLUDEDIR = /usr/local/include/opencv
OPENCV2DIR = /usr/local/include
LIBDIR = /usr/local/lib
LIBS = -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab \
	   -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video \
	   -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core -lopencv_hal -lfreetype -lz

main:img.o CvText.o
	$(CXX) img.o CvText.o -o main -I $(INCLUDEDIR) -I $(OPENCV2DIR) -L $(LIBDIR) $(LIBS) $(CFLAGS)

img.o:img.cpp
	$(CXX) -c img.cpp -o img.o

CvText.o:CvText.cpp
	$(CXX) -c CvText.cpp -o CvText.o

clean:
	rm *.o main -rf

.PHONY:clean all
