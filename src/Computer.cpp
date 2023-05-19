// Ahmet Can SENER
// 150210706


// Computer.cpp => contains definitions of classes and their methods


#include <iostream>
#include "Computer.h"


// Constructor of Computer class
Computer::Computer() {
    std::cout << "Computer is ready" << std::endl;              // prints "Computer is ready"
}


// Definition operator+ method for CPU 
void Computer::operator+(CPU& in_cpu) const{
    if(attachedCPU == nullptr) {
        attachedCPU = &in_cpu;                                  // attaches a CPU to computer if there is not a attached CPU
        std::cout << "CPU is attached" << std::endl;            // prints "CPU is attached"
    } else {
        std::cout << "There is already a CPU" << std::endl;     // prints "There is already a CPU" if there is already a CPU
    }

}


// Definition operator+ method for GPU 
void Computer::operator+(GPU& in_gpu) const {
    if(attachedGPU == nullptr) {
        attachedGPU = &in_gpu;                                  // attaches a GPU to computer if there is not a attached GPU
        std::cout << "GPU is attached" << std::endl;            // prints "GPU is attached"
    } else {
        std::cout << "There is already a GPU" << std::endl;     // prints "There is already a GPU" if there is already a GPU
    }

}


// Definiton execute method for Computer class
void Computer::execute(std::string operation_name) const {
    // if the operation is "render" or "trainModel", delegates it to attachedGPU
    if (operation_name == "render" || operation_name == "trainModel") {
        attachedGPU->execute(operation_name);
    }
    // if the operation is "add" or "subtract" or "multiply", delegates it to attachedCPU
     else if (operation_name == "add" || operation_name == "subtract" || operation_name == "multiply") {
        std::cout << attachedCPU->execute(operation_name) << std::endl;
    }
    
}


// Constructor of CPU class
CPU::CPU(int in_numPerCores) : m_alu(in_numPerCores)    // initializes its Alu object with member initializer list
{
    std::cout << "CPU is ready" << std::endl;           // prints "CPU is ready"

}


// Definition execute method for CPU class
int CPU::execute(std::string operation_name) const{
    int x, y;                                           // two variable for the relevant operation
    std::cout << "Enter two integers" << std::endl;
    std::cin >> x >> y;                                 // user enters the value for the variables
    
    int result;                                         // holds the value of output

    if(operation_name == "add") {
        result = m_alu.add(x, y);                       // if the operations is "add", delegates it to Alu
    } else if(operation_name == "subtract") {
        result = m_alu.subtract(x, y);                  // if the operations is "subtract", delegates it to Alu    
    } else if(operation_name == "multiply") {
        result = m_alu.multiply(x, y);                  // if the operations is "multiply", delegates it to Alu
    }

    return result;                                      // returns the result
}


// Definition of setter method for the CPU's Alu object
void CPU::set_alu(const Alu& in_alu) {
    m_alu = in_alu;
}


// Constructor of GPU class
GPU::GPU(int in_numCores) : m_cuda(in_numCores)         // initializes its Cuda object with member initializer list
{
    std::cout << "GPU is ready" << std::endl;           // prints "GPU is ready"

}


// Definition execute method for GPU class
void GPU::execute(std::string operation_name) const {

    if(operation_name == "render") {
        m_cuda.render();                                // if the operations is "render", delegates it to Cuda
    } else if(operation_name == "trainModel") {
        m_cuda.trainModel();                            // if the operations is "trainModel", delegates it to Cuda
    }

}


// Definition of setter method for the GPU's Cuda object
void GPU::set_cuda(const Cuda& in_cuda) {
    m_cuda = in_cuda;
}


// Constructor of Alu class
Alu::Alu(int in_numPerCores) : m_numPerCores(in_numPerCores) // initializes its m_numPerCores variable with member initializer list
{
    std::cout << "ALU is ready" << std::endl;                // prints "ALU is ready"

}


// Definition of add method
int Alu::add(int x, int y) const{
    return x + y;
}


// Definition of subtract method
int Alu::subtract(int x, int y) const {
    return x - y;
}


// Definition of multiply method
int Alu::multiply(int x, int y) const{
    return x * y;
}


// Definition of setter method for m_numPerCores variable
void Alu::set_numPerCores(int in_numPerCores) {
    m_numPerCores = in_numPerCores;
}


// Constructor of Cuda class
Cuda::Cuda(int in_numCores) : m_numCores(in_numCores)       // initializes its m_numCores variable with member initializer list
{
    std::cout << "CUDA is ready" << std::endl;              // prints "CUDA is ready"

}


// Definition of render method
void Cuda::render() const {
    std::cout << "Video is rendered" << std::endl;
}


// Definition of trainModel method
void Cuda::trainModel() const {
    std::cout << "AI Model is trained" << std::endl;
}


// Definition of setter method for m_numCores variable
void Cuda::set_numCores(int in_numCores) {
    m_numCores = in_numCores;
}




