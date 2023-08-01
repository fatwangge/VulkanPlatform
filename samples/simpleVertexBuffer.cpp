#include "..\\framework\\vulkanBase.h"

#define TEST_CLASS_NAME CSimpleVertexBuffer
class TEST_CLASS_NAME: public CVulkanBase{
public:
	std::vector<Vertex> vertices = {
		{ { 0.0f, -0.5f},{ 1.0f, 0.0f, 0.0f }},
		{ { 0.5f, 0.5f},{ 0.0f, 1.0f, 0.0f }},
		{ { -0.5f, 0.5f},{ 0.0f, 0.0f, 1.0f }}		
	};

	void initialize(){
		//Create bufferss
		wxjCreateVertexBuffer<Vertex>(vertices);
		wxjCreateCommandBuffer();

		wxjCreateSwapChainImagesAndImageViews();

		//Create Renderpass
		VkImageLayout imageLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
		wxjCreateColorAttachment(imageLayout); //add this function will enable color attachment (bUseColorAttachment = true)
		wxjCreateSubpass();
		VkPipelineStageFlags srcPipelineStageFlag = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
		VkPipelineStageFlags dstPipelineStageFlag = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
		wxjCreateDependency(srcPipelineStageFlag, dstPipelineStageFlag);
		wxjCreateRenderPass();

		wxjCreateFramebuffers();

		//Create shader resource
		wxjCreateVertexShader("../shaders/simpleVertexBuffer/vert.spv");
		wxjCreateFragmentShader("../shaders/simpleVertexBuffer/frag.spv");

		//Create Descriptors
		std::vector<VkDescriptorType> descriptorTypes{};
		std::vector<VkShaderStageFlagBits> shaderStageFlagBits{};
		wxjCreateDescriptorPool(descriptorTypes);
		wxjCreateDescriptorSetLayout(descriptorTypes, shaderStageFlagBits);
		wxjCreateDescriptorSets(descriptorTypes);

		wxjCreateGraphicsPipeline<Vertex>(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST, true);

		CApplication::initialize();
	}

	void update(){
		CApplication::update();
	}

	void recordCommandBuffer(){
		wxjBeginCommandBuffer();

		std::vector<VkClearValue> clearValues{ {  0.0f, 0.0f, 0.0f, 1.0f  } };
		wxjBeginRenderPass(clearValues);

		wxjBindPipeline();
		wxjSetViewport();
		wxjSetScissor();
		wxjBindVertexBuffer();
		wxjBindDescriptorSets();
		wxjDraw(3);

		wxjEndRenderPass();
		wxjEndCOmmandBuffer();

		CApplication::recordCommandBuffer();
	}
};

#include "..\\framework\\main.hpp"


