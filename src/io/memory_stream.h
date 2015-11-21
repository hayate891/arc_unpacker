#pragma once

#include <memory>
#include "io/stream.h"

namespace au {
namespace io {

    class MemoryStream final : public Stream
    {
    public:
        MemoryStream();
        MemoryStream(const char *buffer, size_t buffer_size);
        MemoryStream(const bstr &buffer);
        MemoryStream(Stream &other_stream, size_t size);
        MemoryStream(Stream &other_stream);
        ~MemoryStream();

        size_t size() const override;
        size_t tell() const override;
        Stream &seek(size_t offset) override;
        Stream &skip(int offset) override;
        void truncate(size_t new_size) override;

        // specialize most commonly used functions
        u8 read_u8() override;
        u16 read_u16_le() override;
        u32 read_u32_le() override;

        void reserve(size_t count);

    protected:
        void read_impl(void *destination, size_t size) override;
        void write_impl(const void *source, size_t size) override;

    private:
        struct Priv;
        std::unique_ptr<Priv> p;
    };

} }