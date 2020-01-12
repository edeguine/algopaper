# Algopaper

## The app
Algopaper is a small Android app I used to test pattern generation algorithm and provide UI controls.

### App store
The app is currently not on the Google Play store but might be one day.

### Features

The app features a few different image generation algorithms that I am developing as a hobby. This kind of implementation is sometimes referred to as creative coding.

### Screenshots

Here are some screenshots of the algos:
![Pastel](https://raw.githubusercontent.com/edeguine/algopaper/master/images/pastel.png)
![Snake](https://raw.githubusercontent.com/edeguine/algopaper/master/images/snake.png)
![Spiral 1](https://raw.githubusercontent.com/edeguine/algopaper/master/images/spiralfade.png)
![Spiral 2](https://raw.githubusercontent.com/edeguine/algopaper/master/images/spiralfademulti.png)


## The code

### License

The software is free but copyrighted. It is copyrighted under the [JRL license](https://en.wikipedia.org/wiki/Java_Research_License), commercial or proprietary use is forbidden but research and academic use are allowed.

### Implementation details

This projects leverages CPP inside an Android java app.
The code that performs the core of the bitmap manipulation is in the cpp folder.
The code that provides UI and UX (parameters  manipulation) is in the Algopaper subfolder (Android Java app).

### CPP library

To use the CPP code and generate a test image test.png:
```
    cd cpp/test
    make test
    ./test mandala.png
    open test.png
```

You can look in test.cpp to see how the library is used for the various algorithms.
You might need to install libpng.
