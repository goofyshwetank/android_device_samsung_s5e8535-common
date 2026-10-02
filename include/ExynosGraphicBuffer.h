#pragma once

#include <cutils/native_handle.h>
#include <system/graphics.h>
#include <stdint.h>
#include <stddef.h>

namespace vendor {
namespace graphics {

struct ExynosGraphicBufferUsage {
    enum {
        DAYDREAM_SINGLE_BUFFER_MODE = 1ULL << 32,
        PRIVATE_NONSECURE = 1ULL << 33,
    };
};

struct BufferUsage {
    enum {
        DAYDREAM_SINGLE_BUFFER_MODE = 1ULL << 32,
        PRIVATE_NONSECURE = 1ULL << 33,
    };
};

class ExynosGraphicBufferMeta {
public:
    int fd;
    int fd1;
    int fd2;
    int format;
    uint32_t width;
    uint32_t height;
    uint32_t stride;
    uint32_t vstride;
    uint64_t producer_usage;
    uint64_t consumer_usage;
    uint64_t flags;
    size_t size;
    size_t size1;
    size_t size2;

    ExynosGraphicBufferMeta(const native_handle* handle);
    ~ExynosGraphicBufferMeta();

    static int get_format(const native_handle* handle);
    static uint32_t get_width(const native_handle* handle);
    static uint32_t get_height(const native_handle* handle);
    static uint32_t get_stride(const native_handle* handle);
    static uint32_t get_cstride(const native_handle* handle);
    static uint32_t get_vstride(const native_handle* handle);
    static uint64_t get_buffer_id(const native_handle* handle);
    static uint64_t get_producer_usage(const native_handle* handle);
    static uint64_t get_consumer_usage(const native_handle* handle);
    static uint64_t get_usage(const native_handle* handle);
    static uint64_t get_flags(const native_handle* handle);
    static int get_fd(const native_handle* handle, int index);
    static size_t get_size(const native_handle* handle, int index);
    static int get_internal_format(const native_handle* handle);
    static void* get_video_metadata(const native_handle* handle);
    static bool is_afbc(const native_handle* handle);
    static bool is_sajc(const native_handle* handle);
    static uint32_t get_sajc_independent_block_size(const native_handle* handle);
    static uint32_t get_sajc_key_offset(const native_handle* handle);
    static uint32_t get_sajc_sw_mode(const native_handle* handle);
    static void dump(const char* title);
    static void dump_hnd(const native_handle* handle, const char* title);
    static void init(const native_handle* handle);
};

} // namespace graphics
} // namespace vendor
