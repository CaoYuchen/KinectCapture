# KinectCapture
This is a method to capture RGB/Depth from Kinect2 in Windows.

The work is mainly based on [Kincet SDK](https://www.microsoft.com/en-us/download/details.aspx?id=44561) and its ColorBasics-D2D and DepthBasics-D2D examples, with some modification, it can automatically caputre RGB/Depth images, in the situation that CPU i7-7600, RAM 32GB, the program can record all the frames(without lost).

In DepthBasics-D2D, I output 24 bit RGB image, but only 16 bit for Depth pixel from Kinect, then use Merge function to get 16 bit PNG. 

Also, the KincetFusion saves the all the tracking poses and 3D reconstruction model(alternative).
