# Handwriting-Recognition
Implementation of a self organizing map for handwriting recognition using the MNIST dataset of handwritten digits.

**[HERE YOU CAN FIND THE FULL EXPLANATION OF MY PROJECT _(PDF)_](docs/explanation-FR.pdf)** 
## Compilation
The compiler used is GCC and the compilation is cross-platform Linux / MacOS. To compile the project, 2 type options are available:
- Unsigned Char
- Float
The main difference between these two types of compilation is that the project using unsigned char stores the vector weights on a more limited space, making the program faster, this is a small optimization.

***By default the compilation is done with unsigned char.***

### Compilation with Unsigned Char
```bash
make char
```
### Compilation with Float:
```bash
make float
```
## Execution
Here, the generic command to run the program:
```bash
./main dataset Xsize Ysize Learning1 Learning2
```
- Dataset = Number of vectors to be used for learning.
- Xsize = Size X of the 2D matrix.
- Ysize = Size Y of the 2D matrix.
- Learning1 = Number of learning for the first phase (neighborhood of 3). 
- Learning2 = Number of learning for the second phase (around 1).*

Here, the advanced command to run the program in detailed mode:
```bash
./main dataset Xsize Ysize Learning1 Learning2 -V Number_to_produce
```
- -Verbose = Display at each stage of learning the evolution of the neuron network.
- Number_to_produce = Display at each stage of the learning the representation of the number defined by average of each neurons labeled by this number (by default 0).*

## Sources
- http://yann.lecun.com/exdb/mnist/
- https://fr.wikipedia.org/wiki/Base_de_donn%C3%A9es_MNIST
- https://pubmed.ncbi.nlm.nih.gov/19643706/
- http://www.magnusjohnsson.se/Papers/SAIS2010.pdf
