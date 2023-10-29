<p align="center"><img src=".github/gnlbanner.png" alt="Get Next Line banner"/></p>

<p align="justify">The <strong>Get Next Line (GNL)</strong> is a function developed in C that reads text from one or more file descriptors (FDs) and returns one line at a time when calling the get_next_line function.<br><br>With this project I got the opportunity to really understand how to prevent memory leaks and how to allocate just the neccessary space in order to increase the optimization of the code. Furthermore, with the bonus files, not only you can read content from one but from as many file descriptor as you want without losing track of what line you have to return next.</p>

## Project Structure

- [`get_next_line.c`](./get_next_line.c): Main functions for the implementations of the get_next_line.
- [`get_next_line_utils.c`](./get_next_line_utils.c): Utility functions used for the GNL.
- [`get_next_line.h`](./get_next_line.h): Header file for defining used libraries, function prototypes and constants like <code>BUFFER_SIZE</code>

### Bonus
<p align="justify">This project includes a bonus version that supports reading from multiple file descriptors without losing track of the lines of each file descriptor, handling them simultaneosly. For that, it uses an array of buffers. To use the bonus version, compile the *_bonus.c and get_next_line_bonus.h files.</p> 


## Table of Functions

<table>
  <thead>
    <tr>
      <th>Function</th>
      <th>Description</th>
      <th>File(s)</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>get_next_line()</strong></td>
      <td>Reads a line of text from a single file descriptor and returns it.</td>
      <td><a href="get_next_line.c"><code>get_next_line.c</code></a></td>
    </tr>
    <tr>
      <td>🌟<strong>get_next_line()</strong></td>
      <td>The bonus version improves the other one by handling multiple file descriptors without losing track of the last line returned on each file. It uses an array of pointers to manage separate buffers for different file descriptors.</td>
      <td><a href="get_next_line_bonus.c"><code>get_next_line_bonus.c</code></a></td>
    </tr>
    <tr>
      <td><strong>free_str()</strong></td>
      <td>Frees the memory allocated for a string and returns NULL.</td>
      <td><a href="get_next_line.c"><code>get_next_line.c</code></a>, <a href="get_next_line_bonus.c"><code>get_next_line_bonus.c</code></a></td>
    </tr>
    <tr>
      <td><strong>get_result_buffer()</strong></td>
      <td>Updates the buffer by extracting the first line and returning it.</td>
      <td><a href="get_next_line.c"><code>get_next_line.c</code></a>, <a href="get_next_line_bonus.c"><code>get_next_line_bonus.c</code></a></td>
    </tr>
    <tr>
      <td><strong>ft_add_buffer()</strong></td>
      <td>Reads data from the file descriptor into a buffer every <code>BUFFER_SIZE</code> bytes and appends it to an existing buffer until it finishes reading or encounters a new line.</td>
      <td><a href="get_next_line.c"><code>get_next_line.c</code></a>, <a href="get_next_line_bonus.c"><code>get_next_line_bonus.c</code></a></td>
    </tr>
    <tr>
      <td><strong>ft_strlen()</strong></td>
      <td>Calculates the length of a string.</td>
      <td><a href="get_next_line_utils.c"><code>get_next_line_utils.c</code></a>, <a href="get_next_line_utils_bonus.c"><code>get_next_line_utils_bonus.c</code></a></td>
    </tr>
    <tr>
      <td><strong>ft_strdup()</strong></td>
      <td>Duplicates a string.</td>
      <td><a href="get_next_line_utils.c"><code>get_next_line_utils.c</code></a>, <a href="get_next_line_utils_bonus.c"><code>get_next_line_utils_bonus.c</code></a></td>
    </tr>
    <tr>
      <td><strong>ft_substr()</strong></td>
      <td>Extracts a substring from a string.</td>
      <td><a href="get_next_line_utils.c"><code>get_next_line_utils.c</code></a>, <a href="get_next_line_utils_bonus.c"><code>get_next_line_utils_bonus.c</code></a></td>
    </tr>
    <tr>
      <td><strong>ft_gn_strchr()</strong></td>
      <td>Searches for a character in a string and returns the position of its first occurrence.</td>
      <td><a href="get_next_line_utils.c"><code>get_next_line_utils.c</code></a>, <a href="get_next_line_utils_bonus.c"><code>get_next_line_utils_bonus.c</code></a></td>
    </tr>
    <tr>
      <td><strong>ft_gn_strjoin()</strong></td>
      <td>Returns a new string formed by the concatenation of <code>s1</code> and <code>s2</code>.</td>
      <td><a href="get_next_line_utils.c"><code>get_next_line_utils.c</code></a>, <a href="get_next_line_utils_bonus.c"><code>get_next_line_utils_bonus.c</code></a></td>
    </tr>
  </tbody>
</table>


## Usage

### Supported Platforms

- **Linux**
- **macOS**

### Prerequisites

Before using Get Next Line, you need:

- **GCC**: The GNU Compiler Collection.

### Main Example (Bonus - multiple file descriptors)

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd1;
    int fd2;
    char *line;

    // Open files for reading
    fd1 = open("first_file.txt", O_RDONLY);
    fd2 = open("second_file.txt", O_RDONLY);

    if (fd1 == -1 || fd2 == -1)
    {
        printf("Error opening files\n");
        return (1);
    }

    // Read and print lines from fd1
    line = get_next_line(fd1);
    if (line)
    {
        printf("From fd1: %s\n", line);
        free(line);
    }

    // Read and print lines from fd2
    line = get_next_line(fd2);
    if (line)
    {
        printf("From fd2: %s\n", line);
        free(line);
    }

    // Switch back to fd1
    line = get_next_line(fd1);
    if (line)
    {
        printf("From fd1 again: %s\n", line);
        free(line);
    }

    // Close the files
    close(fd1);
    close(fd2);

    return 0;
}
```

### Output Example:
```sh
From fd1: This is the first line from first_line.
From fd2: This is the first line from second_file.
From fd1 again: This is the second line from first_line.
```
