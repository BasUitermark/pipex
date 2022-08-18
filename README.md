<div align="center">

  <img src="assets/piping.png" alt="logo" width="200" height="auto" />
  <h1>PIPEX</h1>
  
  <p>
    Handling multiple system commands through C.
  </p>
</div>
  
  # :notebook_with_decorative_cover: Table of Contents

- [About the Project](#star2-about-the-project)
  * [Features](#dart-features)
- [Getting Started](#toolbox-getting-started)
  * [Installation](#gear-installation)
- [Usage](#eyes-usage)
- [Roadmap](#compass-roadmap)
- [Contact](#handshake-contact)



## :star2: About the Project

A project made in accordance with the Pipex project for the Codam Core Curriculum.
Teaches how to use piping, create forks and change the STDIN and STDOUT through dup2.




### :dart: Features

Handles multiple commands from the commandline, processes them through pipes and outputs it into a designated output file.




## 	:toolbox: Getting Started

### :gear: Installation

Start by cloning the repository into your projects includes filder:
```c
git clone https://github.com/BasUitermark/pipex.git
```

Compile by using make:
```c
make
```

Don't forget to include the library in your project:
```c
#include "includes/pipex.h"
```

Or if you add the library path to your header file:
```c
#include "pipex.h"
```



## :eyes: Usage

```c
./pipex [/infile.txt] command1 command2 [/outfile.txt]
```



## :compass: Roadmap

Nothing to do here.


## :handshake: Contact

See my profile page for ways to contact me!
