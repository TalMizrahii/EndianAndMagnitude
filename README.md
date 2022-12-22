
<h1 align="center">
  
<br>
  EndianAndMagnitude - Computer Systems course
  <br>
</h1>

<h4 align="center">This gitHub repository is for the Third assignment given in Computer Systems course, Bar Ilan University.


<p align="center">
  <a href="#description">Description</a> •
  <a href="#installing-and-executing">Installing And Executing</a> •
  <a href="#author">Author</a> 
</p>

## Description

 This project is the first assignment in the Computer Systems course. Its purpose is to enlarge my understanding of the representation of bytes in different computers.
 
There are 3 parts to this project:
  * Write a function that tells if the computer you run this program on is using [Big Endian](https://en.wikipedia.org/wiki/Endianness) represantaion or [Little Endian](https://en.wikipedia.org/wiki/Endianness) representation. If it uses Big Endian, it will print 0. if it uses Little Endian, it will print 1. 
  
  * Write a function which receives an array of 8 bytes of boolean values, and calculate its decimal representation in [Two's Complement](https://en.wikipedia.org/wiki/Two%27s_complement).  
  
  * Write a function which receives an array of 8 bytes of boolean values, and calculate its decimal representation in [Sign-Magnitude](https://en.wikipedia.org/wiki/Signed_number_representations).  

## Installing And Executing

To clone and run this application, you'll need to use [Git](https://git-scm.com) and the [gcc](https://gcc.gnu.org/) compiler. From your command line:

```bash
# Clone this repository.
$ git clone https://github.com/TalMizrahii/Assembly-Pstrings

# Go into the repository.
$ cd Assembly-Pstrings

# Compile the program.
$ gcc run_main.s func_select.s pstring.s

# Run the program (Linux).
$ ./a.out
```

## Author
* [@Tal Mizrahi](https://github.com/TalMizrahii)
