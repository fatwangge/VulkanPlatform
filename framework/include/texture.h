#ifndef H_TEXTURE
#define H_TEXTURE

#include "imageBuffer.h"
#include "renderer.h"

class CTextureImage final{
public:
    CTextureImage();
    ~CTextureImage();
    void Destroy();

    void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
    VkCommandBuffer beginSingleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);
    void transitionImageLayout(VkImage image, VkImageLayout oldLayout, VkImageLayout newLayout);
#ifndef ANDROID
    void CreateTextureImage(const std::string texturePath, VkImageUsageFlags usage, VkCommandPool &commandPool);
#else
    void CreateTextureImage(std::vector<uint8_t>& fileBits, VkImageUsageFlags usage, VkCommandPool &commandPool);
#endif
    void CreateTextureImage(uint8_t* pixels, VkImageUsageFlags usage, CWxjImageBuffer &imageBuffer);
    void CreateImageView(VkImageAspectFlags aspectFlags);

    void generateMipmaps();
    void generateMipmaps(VkImage image, bool bMix = false, std::array<CWxjImageBuffer, MIPMAP_TEXTURE_COUNT> *textureImageBuffers_mipmaps = NULL);
    void generateMipmaps(std::string rainbowCheckerboardTexturePath, VkImageUsageFlags usage);

    //Resource for Texture
    int32_t texWidth, texHeight;
    VkFormat imageFormat;
    //std::string texturePath = "";
	//VkSampler textureSampler;
	CWxjImageBuffer textureImageBuffer;
	//VkImageView textureImageView;

    VkCommandPool *pCommandPool;

    uint32_t mipLevels = 1; //1 means no mipmap
    bool bEnableMipMap = false;

    //CDebugger * debugger;
};

#endif