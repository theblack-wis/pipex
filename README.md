# pipex
<center>
  <h1> Pipex ? test allowd function ? <h1>
</center>
<p>

```
    open, close, read, write, malloc, free
```
    
  New function :
  
        perror : void perror(const char *str); 

<table>
  <thead>
    <tr>
      <th>Funtion name</th>
      <th>Library</th>
      <th>Prototype</th>
      <th>Descriptio</th>
      <th>Source Link</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>perror</th>
      <th>"stdio.h"</th>
      <th><pre>void perror(const char *str)</pre></th>
      <th><p>Prints a descriptive error message to stderr.</p></th>
      <th><a href="https://www.tutorialspoint.com/c_standard_library/c_function_perror.htm" target="_blank" > more info </a> </th>
    </tr>
    <tr>
      <th>strerror</th>
      <th>"stdio.h" "errno.h" "string.h" </th>
      <th><pre>char *strerror(int errnum)</pre></th>
      <th><p>Searches an internal array for the error number errnum and returns a pointer to an error message string. The error strings produced by strerror depend on the developing platform and compiler.</p></th>
      <th><a href="https://www.tutorialspoint.com/c_standard_library/c_function_strerror.htm" target="_blank" > more info </a> </th>
    </tr>
    <tr>
      <th>access</th>
      <th>"unistd.h"</th>
      <th><pre>int access(const char *pathname, int mode)</pre></th>
      <th><p>Check whether a file exists or not / first argument takes the path to the directory/file and the second argument takes flags <small>R_OK, W_OK, X_OK or F_OK.</small></p></th>
      <th><a href="https://www.geeksforgeeks.org/access-command-in-linux-with-examples/" target="_blank" > more info </a> </th>
    </tr>
    <tr>
      <th>dup && dup2 </th>
      <th>"unistd.h"</th>
      <th><pre>int dup(int fildes)
               int dup2(int fildes, int fildes2)</pre>
      </th>
      <th><p>The dup() system call creates a copy of a file descriptor <br><hr><br> The dup2() system call is similar to dup() but the basic difference between them is that instead of using the lowest-numbered unused file descriptor, it uses the descriptor number specified by the user.</p></th>
      <th><a href="https://www.geeksforgeeks.org/dup-dup2-linux-system-call/" target="_blank" > more info </a> </th>
    </tr>
    <tr>
      <th>execve</th>
      <th>"unistd.h"</th>
      <th><pre>int execve(const char *path, char 
            *const argv[], char *const envp[])</pre>
      </th>
      <th><p>The execve() function replaces the current process image with a new process image specified by path. The new image is constructed from a regular, executable file called the new process image file</p></th>
      <th><a href="http://www.qnx.com/developers/docs/qnxcar2/index.jsp?topic=%2Fcom.qnx.doc.neutrino.lib_ref%2Ftopic%2Fe%2Fexecve.html" target="_blank" > more info </a> </th>
    </tr>
    <tr>
      <th>exit</th>
      <th>"stdio.h"</th>
      <th><pre>void exit (int code)</pre></th>
      <th><p>Used to break out of a loop. This function causes an immediate termination of the entire program done by the operation system.</p></th>
      <th><a href="https://www.tutorialspoint.com/what-is-exit-function-in-c-language" target="_blank" > more info </a> </th>
    </tr>
  </tbody>
  </table>

</p>
