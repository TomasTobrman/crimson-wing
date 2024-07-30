#include "garrulus/window.h"

#include <X11/X.h>
#include <X11/Xlib.h>

void open_test_window() {
    XEvent event;
    Display *display = XOpenDisplay(NULL);
    Window window = XCreateSimpleWindow(display, DefaultRootWindow(display), 100, 100, 640, 480, 1, BlackPixel(display, 0), WhitePixel(display, 0));
    XMapWindow(display, window);
    XSelectInput(display, window, ExposureMask);

    for (;;) {
        XNextEvent(display, &event);
        if (event.type == Expose) {
            XDrawString(display, window, DefaultGC(display, 0), 100, 100, "Hello There", 11);
        }
    }
}
