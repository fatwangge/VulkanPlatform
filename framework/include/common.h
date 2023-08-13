#ifndef H_COMMON
#define H_COMMON


//#define ANDROID

#define GLM_FORCE_RADIANS
#ifndef ANDROID
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#else
#include "../../thirdparty/GLM/glm/glm.hpp"
#include "../../thirdparty/glm/gtc/matrix_transform.hpp"
#endif

// #define GLM_FORCE_DEPTH_ZERO_TO_ONE
// #define GLM_ENABLE_EXPERIMENTAL
//#include <glm/gtx/hash.hpp>
#include <unordered_map>

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string> 
#include <cstring>

#include <optional>
#include <array>
#include <vector>
#include <set>
#include <unordered_map>

#include <algorithm>
#include <chrono>

#include <memory>

//not sure usefulness...
// #include <stdexcept>
// #include <cstdlib>
// #include <cstdint>
// #include <limits>

const uint32_t WINDOW_WIDTH = 1024;
const uint32_t WINDOW_HEIGHT = 800;
const int MAX_FRAMES_IN_FLIGHT = 2;

const int MIPMAP_TEXTURE_COUNT = 7;

#define IN
#define OUT
#define INOUT


//#define NDEBUG
#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

#define PALLOCATOR		(VkAllocationCallbacks *)nullptr

//#include "debugger.h"
#include <vulkan/vulkan.h>

#endif