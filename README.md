# Progression Library

A header-only C++ progression library implementing arithmetic, geometric, and Fibonacci progressions.

## Features
- Arithmetic progressions
- Geometric progressions  
- Fibonacci sequences
- Easy-to-use interface

## Usage
```cpp
#include "progression.hpp"

int main(){
    Progression *ap = new ArithProgression(2, 3);
    ap->print_progression(10);

    delete ap;
    return 0;
}

```
## To see the documentation for the core logic, please check the **[Progression](classProgression.html)** class.
