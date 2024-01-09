<p float="left">
  <img src="https://github.com/gpuwangge/VulkanPlatform/blob/main/images/vulkanLogo.png" alt="alt text" width="150" height="120">  
  <img src="https://github.com/gpuwangge/VulkanPlatform/blob/main/images/windowsLogo.png" alt="alt text" width="150" height="120">  
  <img src="https://github.com/gpuwangge/VulkanPlatform/blob/main/images/androidLogo.png" alt="alt text" width="220" height="120">  
</p>


# Vulkan Cross-Platform Game Engine
![Windows](https://img.shields.io/badge/Windows-passing-brightgreen)
![Android](https://img.shields.io/badge/Android-passing-brightgreen)
- Build windows and android binary with same sample code!

<img src="https://github.com/gpuwangge/VulkanPlatform/blob/main/images/shadowMapAVDDemo.png" alt="alt text" width="170" height="330">  

## How to build to Windows binary(.exe)
Prepare:  
1. Install Vulkan  
1. Install CMake  
1. Setup GLFW (Or use SDL at your preference)  
1. Setup GLM
1. git clone this repo 
- [Optional] Download other thirdparty headers: stb_image.h and tiny_obj_loader.h (I already put both files in the "thirdparty" folder in this repo)  
### for all samples
mkdir build  
cd build  
cmake -G "MinGW Makefiles" ..   
make  

### for one sample  
mkdir build  
cd build  
cmake -G "MinGW Makefiles" -D SINGLE=true ..  
make  
- [Optional] Edit CMakeLists.txt to tell compiler which sample to build   

## How to build to Android binary(.apk)
Prepare:  
1. Install Android Studio: https://developer.android.com/   
Android SDK Build-Tools 34: 30.0.3  
2. Install NDK: https://developer.android.com/studio/projects/install-ndk  
   You only need to install&setup NDK. You should already installed and configured CMake when installing Vulkan. 
NDK: 25.1.8937393  
- [Optional] To verify setup success or not, make sure to run these tests: https://github.com/android/ndk-samples  
   Especially the "hello-vulkan" test.  
### for one sample    
Launch Android Studio, open "androidSandbox" folder.   Select "Build" > "Build Bundle(s) / APK(s) > Build APK(s)"  
- [Optional] Edit samples/androidSample.h to tell Android Studio which sample to build  
- [Optional] If you want to run sample on AVD(Android Virtual Device), in the Android Studio, click the green button on the top right corner.  

## How to debug in Android Studio
- When device is connected, Run 'app' will launch on device  
- When device is not conntected, Run 'app' will launch AVD, then you can click the green triangle button on the bar to start app  

## Distribution
- For Android, just distribute the single .apk file, it contains all resources.  
- For Windows, it is more complicated. Besides the .exe binary, you should include the following resources(if the sample use any):  
models/  
shaders/  
textures/  
Also include the following dynamic libs:  
glfw3.dll  
libgcc_s_seh-1.dll  
libstdc++-6.dll  
vulkan-1.dll  

## Troubleshooting
- Windows binary can not run because missing vulkan-1.dll  
This is because Vulkan SDK or Vulkan Runtime is not installed.  
Solution is to install Vulkan SDK(https://vulkan.lunarg.com/sdk/home#windows)  
If you only want to distribute the binary, only download Vulkan Runtime, unzip and copy vulkan-1.dll to the binary folder  
- Windows binary can not run because missing libstdc++-6.dll or/and libgcc_s_seh-1.dll  
This is because MinGW is not installed. Install MinGW will solve this issue.  
If you only want to distribute the binary, copy libstdc++-6.dll or/and libgcc_s_seh-1.dll from C:\mingw64\bin (or where you install MinGW) to the binary folder  
- Windows binary has no error message but nothing shows up or it simply CTD(crash to desktop)  
Most likely hardware(GPU) does not support Vulkan; or you are using virtual machine that has no GPU support.  
You can verify this by installing Vulkan SDK, and runing the test under Bin/vkcube.exe.  
Solution is to not use virtual machine, and buy a real physical graphics card(that supports Vulkan, which most will do) at https://www.amazon.com/ (or whatever e-commerce website)  
- In Android Studio, when Debug 'app', AVD stucks at "Waiting For Debugger" forever  
One reason is that there are multiple virtual devices and the debugger is stuck on one of them.   
Delete these virtual devices and leave only one.  
(I use **Pixel 7 Pro API 30, Android 11.0 Google Play | x86**)  


## References
https://github.com/StanislavPetrovV/FurMark  
https://github.com/SaschaWillems/Vulkan  
https://github.com/KhronosGroup/Vulkan-Samples  
https://github.com/nothings/stb/tree/master  
https://github.com/tinyobjloader/tinyobjloader  
https://vulkan-tutorial.com/  
https://web.engr.oregonstate.edu/~mjb/vulkan/  
https://github.com/android/ndk-samples  

