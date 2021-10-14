/**
 * @file factory.cpp
 * @author Ivan Mercep
 * @brief
 * Example of the Factory design pattern
 * with polymorphism and smart pointers
 * @version 0.1
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <memory>

class GraphicsApi
{
    std::string name;

public:
    GraphicsApi(std::string name)
        : name(name){};
    virtual ~GraphicsApi(){};

    virtual void do_stuff() = 0;
    std::string get_name()
    {
        return this->name;
    }
};

class VulkanGraphicsApi : public GraphicsApi
{
public:
    VulkanGraphicsApi()
        : GraphicsApi("Vulkan"){};
    virtual ~VulkanGraphicsApi(){};

    void do_stuff()
    {
        std::cout << "do_stuff: VulkanApi\n";
    }
};

class OpenGlGraphicsApi : public GraphicsApi
{
public:
    OpenGlGraphicsApi()
        : GraphicsApi("OpenGL"){};
    virtual ~OpenGlGraphicsApi(){};

    void do_stuff()
    {
        std::cout << "do_stuff: OpenGLApi\n";
    }
};

struct Config
{
    // should be loaded in runtime and use enum
    inline static std::string gApi = "vulkan";
};

std::unique_ptr<GraphicsApi> graphicsApiFactory()
{
    if (Config::gApi == "vulkan")
        return std::make_unique<VulkanGraphicsApi>();
    else
        return std::make_unique<OpenGlGraphicsApi>();
}

int main(int argc, char **argv)
{
    std::unique_ptr<GraphicsApi> gApi = graphicsApiFactory();
    gApi->do_stuff();
    std::cout << "Name is " << gApi->get_name() << "\n";
    return 0;
}