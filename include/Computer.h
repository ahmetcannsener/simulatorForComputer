// Ahmet Can SENER 
// 150210706


// Computer.h => header file that contains the declarations of the 5 classes.


// Cuda Class declaration - A class that has render() and trainModel() methods, and an integer m_numCores variable, representing the number of CUDA cores.
class Cuda{
    public:
        Cuda(int);                                      // Constructor to initialize number of Cores    
        void render() const;                            // const method returns the result as "Video is rendered"
        void trainModel() const;                        // const method returns the result as "AI Model is trained"    
        int get_numCores() const {return m_numCores;}   // Accessor for number of Cores 
        void set_numCores(int);                         // Setter method for number of Cores. Setter is not constant 
    private:
        int m_numCores;                                 // m_numCores variable represents the number of CUDA cores.
};


// Alu Class declaration - A class contains add, subtract and multiply methods
class Alu{
    public:
        Alu(int);                                           // Constructor to initialize number of ALUs per CPU core.
        int add(int, int) const;                            // const method for addition operation for two integers
        int subtract(int, int) const;                       // const method for subtraction operation for two integers
        int multiply(int, int) const;                       // const method for multiplication operation for two integers    
        int get_numPerCores() const {return m_numPerCores;} // Accessor for number of ALUs per CPU core
        void set_numPerCores(int);                          // Setter method for number of ALUs per CPU core
        //setter is not constant   
    private:
        int m_numPerCores;                                  // m_numPerCore variable represents the number of ALUs per CPU core.
};


// CPU class declaration - CPU can execute relevant operations with execute method. It reads two integers from the keyboard, delegates the operation to the ALU, and returns the result
class CPU{
    public:
        CPU(int);                                           // Constructor to initialize Alu object
        int execute(std::string) const;                     // const method for relevant operations to be delegated to Alu 
        const Alu& get_alu() const {return m_alu;}          // Accessor for the Alu object  
        void set_alu(const Alu&);                           // Setter method for setting Alu. Setter is not constant
    private:
        Alu m_alu;                                          // Alu attribute of CPU class
};


// GPU class declaration - GPU can execute operations with execute method. Within this method, it uses its cuda for operations and returns the result
class GPU{
    public:
        GPU(int);                                           // Constructor to initialize Cuda object        
        void execute(std::string) const;                    // const method for relevant operations to be delegated to Cuda
        const Cuda& get_cuda() const {return m_cuda;}       // Accessor for the Cuda object
        void set_cuda(const Cuda&);                         // Setter method for setting Cuda. Setter is not constant
    private:
       Cuda m_cuda;                                         // Cuda attribute of GPU class
};


// Computer class declaration - CPU and GPU can be attached to a computer using the "+" operator. To execute an operation on the computer, execute method is called by giving the operation name as an argument.
class Computer{
    public:
        Computer();                                         // Constructor for computer class
        void operator+( CPU&) const;                         // operator overloading for "+". This const method attaches a CPU to the computer.              
        void operator+( GPU&) const;                         // operator overloading for "+". This const method attaches a GPU to the computer.
        void execute(std::string) const;                    // const execute method. execute method is called by giving the operation name as an argument
    private:
        mutable CPU* attachedCPU = nullptr;                 // a pointer to CPU. mutable keyword is used because it is modifiable by a const method (operator+ method)
        mutable GPU* attachedGPU = nullptr;                 // a pointer to GPU. mutable keyword is used because it is modifiable by a const method (operator+ method)
};





