#include "..\\framework\\vulkanBase.h"

class CSimpleTriangle: public CVulkanBase{
	std::vector<VkDescriptorType> descriptorTypes{VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER};
	std::vector<VkShaderStageFlagBits> shaderStageFlagBits{VK_SHADER_STAGE_VERTEX_BIT};
public:
    CSimpleTriangle(){
		/************
		buffersize: 8(numbers each vertex)*4(float)*4(vertex size)=128（byte）
		************/
		vertices3D = {
		 	{ { -0.5f, -0.5f, 0.0f },{ 1.0f, 0.0f, 0.0f },{ 1.0f, 0.0f } },
		 	{ { 0.5f, -0.5f, 0.0f },{ 0.0f, 1.0f, 0.0f },{ 0.0f, 0.0f } },
		 	{ { 0.5f, 0.5f, 0.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 1.0f } },
		 	{ { -0.5f, 0.5f, 0.0f },{ 1.0f, 1.0f, 1.0f },{ 1.0f, 1.0f } }
		 };

		/************
		buffer size: 6*4=24（byte）
		************/
		indices3D = { 0, 1, 2, 2, 3, 0};

		vertexShaderPath = "../shaders/basic/vert.spv";
    	fragmentShaderPath = "../shaders/basic/frag.spv";

		/*****
		 * Other things to prepare
		 * Renderpass: colorAttachment, depthAttachment(for model), colorAttachmentResolve(for MSAA)
		 * Framebuffer: swapChainImageViews[i], depthImageView(for model), colorImageView_msaa(for MSAA)
		 * Descriptor: VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER (for MVP),VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER (for texture), VK_DESCRIPTOR_TYPE_STORAGE_BUFFER (for compute shader)
		 * ****/
    }

    ~CSimpleTriangle(){

    }

	void updateUniformBuffer(uint32_t currentFrame, float durationTime) {

		CVulkanBase::updateUniformBuffer(currentFrame, durationTime);
	}

	void update(){
		//printf("triangle update...\n");

		CVulkanBase::update();
	}

	void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex) {
		CVulkanBase::recordCommandBuffer(commandBuffer, imageIndex);
	}

	void drawFrame(){
		//printf("triangle drawFrame...\n");

		CVulkanBase::drawFrame();
	}

	void initVulkan(){
		printf("simpleTriangle init\n");
		CVulkanBase::initVulkan();
	}

	void CreateRenderPass() {
		wxjCreateColorAttachment();
		//wxjCreatDepthAttachment();
		//wxjCreatColorAttachmentResolve();
		wxjCreateSubpass();
		wxjCreateDependency();
		wxjCreateRenderPass();
	}

	void CreateFramebuffers() {
		wxjCreateFramebuffers();
	}

	void CreateDescriptorPool(){
		wxjCreateDescriptorPool(descriptorTypes);
	}
    void CreateDescriptorSetLayout(){
		wxjCreateDescriptorSetLayout(descriptorTypes, shaderStageFlagBits);
	}
    void CreateDescriptorSets(){
		wxjCreateDescriptorSets(descriptorTypes);
	}

	void CreateGraphicsPipeline(){
		wxjCreateGraphicsPipeline(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST);
	}	

	void CreateImageTexture(){
	}
};

int main(){
	CSimpleTriangle app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
    return 0;
}