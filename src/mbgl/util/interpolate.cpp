#include <mbgl/util/interpolate.hpp>

#include <cmath>

namespace mbgl {
namespace util {

float interpolationFactor(float base, Range<float> range, float z) {
    const float zoomDiff = range.max - range.min;
    const float zoomProgress = z - range.min;
    if (zoomDiff == 0) {
        return 0;
    } else if (base == 1.0f) {
        return zoomProgress / zoomDiff;
    } else {
        return static_cast<float>((std::pow(static_cast<double>(base), zoomProgress) - 1) /
                                  (std::pow(static_cast<double>(base), zoomDiff) - 1));
    }
}

} // namespace util
} // namespace mbgl
