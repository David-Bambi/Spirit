#ifndef UGLAD_HPP
#define UGLAD_HPP

#include <exception>

namespace uglad
{

struct FailedInitGladException : public std::exception
{
    [[nodiscard]]
    const char* what() const noexcept override
    {
        return "Failed to initialize GLAD";
    };
};

void GladInit();
} // namespace uglad

#endif
