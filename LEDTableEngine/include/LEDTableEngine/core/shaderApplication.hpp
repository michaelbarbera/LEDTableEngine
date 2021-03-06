#ifndef _H_SHADER_BASE_APP_
#define _H_SHADER_BASE_APP_

#include <complex>

#include <LEDTableEngine/core/baseApplication.hpp>

namespace led {
/**
 * @brief Base class for applications that do pixelwise rendering (similar
 * to shaders). Input is handeled automatically (iterating through all shader types
 * in the implementation). Drawing is simpilfied to a pe-pixel render function.
 */
class ShaderApplication : public led::BaseApplication {
protected:

    size_t m_shaderCnt;
    size_t m_shaderCurrId;

public:

    ShaderApplication();
    virtual ~ShaderApplication();
    /**
     * Initialize application.
     * @param ctrl
     * @param shaderCnt Specify the number of available shaders. Used for
     * looping through all shaders if the user presses a key.
     */
    virtual void initialize(led::BaseController *ctrl,
                            size_t shaderCnt);

    virtual void processInput(const led::BaseInput::InputEvents& events,
                              led::TimeUnit deltaTime);
    virtual void draw(led::Image& frame);

protected:

/**
 * Implement this function!
 * The function will be called once for each pixel.
 * It provides the current time, the image coordinates and
 * the shader id, selected by the user.
 * Return the resulting color for each pixel by reference.
 */
    virtual void renderPixel(led::TimeUnit tm,
                             size_t x,
                             size_t y,
                             uint8_t     & r,
                             uint8_t     & g,
                             uint8_t     & b,
                             size_t shaderId) = 0;
};
}

#endif // ifndef _H_SHADER_BASE_APP_
