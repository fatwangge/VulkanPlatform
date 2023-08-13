#ifndef H_APPLICATION
#define H_APPLICATION

#include "common.h"
#include "camera.hpp"
#include "instance.h"
#include "swapchain.h"
#include "dataBuffer.hpp"
#include "context.h"
#include "descriptor.h"
#include "renderProcess.h"
#include "shaderManager.h"
#include "renderer.h"
#include "texture.h" //this includes imageManager.h
#include "modelManager.h"
#include "glfwManager.h"


#define RENDER_START { \
    renderer.Start(renderProcess.graphicsPipeline, renderProcess.pipelineLayout, \
    renderProcess.renderPass,   \
    swapchain.swapChainFramebuffers,swapchain.swapChainExtent,   \
    descriptor.descriptorSets,  \
    clearValues);}
#define RENDER_END renderer.End();

class CApplication{
public:
    CApplication();
    ~CApplication();

    //VkInstance instance;//01
    std::unique_ptr<CInstance> instance{nullptr};

    VkSurfaceKHR surface;//03
    
    bool framebufferResized = false;

    //CDebugger * debugger;

	CSwapchain swapchain;
    CRenderProcess renderProcess;
    CShaderManager shaderManager;
    CDescriptor descriptor;
    CRenderer renderer;
    CTextureImage textureImage;
    CModelManager modelManager;
    CGLFWManager glfwManager;

    //std::chrono::_V2::system_clock::time_point lastTime;

    void run();

    void mainLoop();

    //for static class member. But can not define and init them in the header file!
    static Camera mainCamera; 
    static bool NeedToExit;

    /*Clean up Functions*/
    void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
    
    float durationTime = 0;
    float deltaTime = 0;

    /*Virtual function: base and derived class will implement. If drived class not implement, call base's verson*/
    virtual void initialize(); //base: create sync object, destroy shader resource
    virtual void update(); //base: update time, frame id, camera and ubo
    
    /*Pure virtual function(=0): base class not implment, derived class must implement*/
    virtual void recordCommandBuffer() = 0;
};

#endif