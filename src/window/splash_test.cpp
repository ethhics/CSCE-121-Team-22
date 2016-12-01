#include "../defs.h"
#include "../windows.h"

int main()
try {
          splash_screen win {Point{100,100},800,600,"Digit Fidgit"};
          return gui_main();
}
catch(exception& e) {
          cerr << "exception: " << e.what() << '\n';
          return 1;
}
catch (...) {
          cerr << "Some exception\n";
          return 2;
}
