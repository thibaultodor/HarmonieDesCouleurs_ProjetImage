#include <iostream>
#include <cmath>

void RGBtoHSL(int r, int g, int b, double &h, double &s, double &l) {
    double rd = static_cast<double>(r) / 255.0;
    double gd = static_cast<double>(g) / 255.0;
    double bd = static_cast<double>(b) / 255.0;

    double max_color = std::max(std::max(rd, gd), bd);
    double min_color = std::min(std::min(rd, gd), bd);
    double delta = max_color - min_color;

    if (delta == 0) {h = 0;}
    else if (max_color == rd) { h = fmod(((gd - bd) / delta), 6);}
    else if (max_color == gd) { h = ((bd - rd) / delta) + 2;}
    else {h = ((rd - gd) / delta) + 4;}
    h = (h * 60.0) / 360.0;

    if (h < 0) {h += 1.0;}
    l = (max_color + min_color) / 2.0;
    if (delta == 0) {s = 0;}
    else {s = delta / (1.0 - fabs(2.0 * l - 1.0));}
}

int main() {
    int r = 255;
    int g = 51;
    int b = 204;
    double h, s, l;
    RGBtoHSL(r, g, b, h, s, l);
    std::cout << "RGB(" << r << ", " << g << ", " << b << ")" << std::endl;
    std::cout << "HSL(" << h << ", " << s << ", " << l << ")" << std::endl;
    return 0;
}
