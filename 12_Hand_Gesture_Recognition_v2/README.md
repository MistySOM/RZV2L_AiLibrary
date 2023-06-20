# RZV2L AI Library - Hand Gesture Recognition with Camera mode

## Introduction

This application showcases the capability of deep neural networks to predict different hand gestures.
Hand gesture recognition application is available now with better usability. 

sample video on YouTube -[Hand gesture recognition demo video](https://youtu.be/jqCSphkcyik)

## Hand Gesture Recognition Application details
```
|-- Hand_Gesture_Recognition_v2_cam # Application with CORAL camera input
|   |-- Makefile
|   |-- etc # address map and pre/post process configuration of both hand gesture recognition (resnet18) and tiny-yolov3 (hand detection)
|   |-- exe
|   |   |-- hagrid_labels.txt # Gesture labels
|   |   |-- hand_gesture_recognition_v2_cam_app # The executable
|   |   |-- resnet18_cam # DRP-AI files of hand gesture
|   |   `-- tinyyolov3_cam # DRP-AI files of tiny-yolov3
|   `-- src # source code directory
|-- Hand_Gesture_Recognition_v2_usbcam # Application with USB camera input
|   |-- Makefile
|   |-- etc # address map and pre/post process configuration of both hand gesture recognition (resnet18) and tiny-yolov3 (hand detection)
|   |-- exe
|   |   |-- hagrid_labels.txt # Gesture labels
|   |   |-- hand_gesture_recognition_v2_usbcam_app # The executable
|   |   |-- resnet18_cam # DRP-AI files of hand gesture
|   |   `-- tinyyolov3_cam # DRP-AI files of tiny-yolov3
|   `-- src # source code directory
`-- README.md
```

### Model Details
1) TinyYolov3 

Tinyyolov3 is used to detect hands from the camera input. The bounding box is drawn for the detected hands. The model is pretrained model. 

Model Reference https://github.com/cansik/yolo-hand-detection

2) Resnet18

Pretrained Resnet18 based classifier is used to recognize hand gesture from the detected hands. The classifier is trained on HAgrid (HAnd Gesture And Gesture Recognition Image Dataset) dataset.

Model Reference https://github.com/hukenovs/hagrid
This work (repository) is licensed under a variant of Creative Commons Attribution-ShareAlike 4.0 International License.
Please see the specific license at above mentioned GitHub page.

### Application with camera input


1)Camera input is fed to object detector (tiny yolov3) to detect hands.
2)Detected hands are used by resnet18 based hand gesture classifier to predict hand gesture. 

## Running the application
### How to build the sample application

Please follow the below steps:

```
cd $work_dir
git clone https://github.com/Ignitarium-Renesas/RZV2L_AiLibrary 
cd RZV2L_AiLibrary/12_Hand_Gesture_Recognition_v2/Hand_Gesture_Recognition_v2_<cam/usbcam>
make

### Running the sample application

1. Now, copy the `RZV2L_AiLibrary` directory to the board (/home/root/).
2. Please follow these steps:

```
cd /home/root/RZV2L_AiLibrary 
cd 12_Hand_Gesture_Recognition_v2/Hand_Gesture_Recognition_v2_<cam/usbcam>/exe
./hand_gesture_recognition_v2_<cam/usbcam>_app
```

#### Example:
```
cd /home/root/RZV2L_AiLibrary 
cd 12_Hand_Gesture_Recognition_v2/Hand_Gesture_Recognition_v2_usbcam/exe
./hand_gesture_recognition_v2_usbcam_app
```
## Limitation
1. The prediction works best when the distance between camera and hand is in between 0.5 - 1.0 metre.
2. The accuracy improves with minimum background noise or movement. 

### Known issues:
- [ERROR] Failed to initialize Coral Camera - This error is observed if camera is not connected to the board. Check camera connection properly. Connect and restart the board.
- permission denied - This error may occur if executable file does not have execution permission. Use this command - `chmod 777 executable_filename` to assign proper permissions.