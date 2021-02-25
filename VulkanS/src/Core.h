#pragma once
#define VK_ENABLE_ASSERTS

#ifdef VK_ENABLE_ASSERTS
#define VK_ASSERT(x,...) { if (!(x)) {  VK_ERROR("Assertion failed: {0}",__VA_ARGS__); __debugbreak(); } }


#else
#define VK_ASSERT(x,...) 
#endif // VK_ENABLE_ASSERTS
