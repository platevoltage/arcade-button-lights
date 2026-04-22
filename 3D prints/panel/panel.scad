// Parameters
width_bottom = 1000;
width_top    = 950;
height       = 500;
top_curve_r  = 50;    // how “deep” the top curve is
segments     = 32;    // number of points for the curve

// Create points for the top curved edge
function top_curve_points(left, right, y, r, n) =
    [ for (i = [0:n]) let(t = i/n)
        [ left + t*(right-left), y + r*(sin(t*180 * PI/180)) ] ];

// Module for trapezoid with curved top
module trapezoid_top_curved() {
    bottom_left  = [-width_bottom/2, 0];
    bottom_right = [ width_bottom/2, 0];
    top_left     = [-width_top/2, height];
    top_right    = [ width_top/2, height];

    points = concat(
        [bottom_left, bottom_right],                        // bottom edge
        top_curve_points(top_left[0], top_right[0], top_left[1], top_curve_r, segments)  // top edge
    );

    polygon(points);
}

// Extrude to 3D
linear_extrude(height=50)
    trapezoid_top_curved();