
color(c = "#440000")  rotate([180, 0, 270]) translate([-40, -20, -1.5]) import("main-board.stl");
color(c = "#004400")  rotate([90, 0, 270]) translate([-137.5, 50, -33.5]) import("io-board.stl");
$fn = 100; 



difference() {
    union() {
        for (r = [0, 90, 180, 270])
            rotate([0, 0, r]) translate([25, -12.5, -19.5]) linear_extrude(height = 18) square([2, 6]);

        for (r = [0, 90, 180, 270])
            rotate([0, 0, r]) translate([25, -12.5, -12]) linear_extrude(height = 8) square([8, 6]);
        translate([0, 0, -8]) linear_extrude(height = 8) square([64, 76], center=true);
        for (r = [0, 180])
            rotate([0, 0, r]) translate([0, 35, -42]) linear_extrude(height = 42) square([64, 6], center=true);
        for (r = [0, 180])
            rotate([0, 0, r]) translate([0, -32.5, -38]) linear_extrude(height = 38) circle(d = 10);
    }

    union() {
        translate([0, 0, -10]) linear_extrude(height = 12) square([49.5, 49.5], center=true);
        for (r = [0, 180])
            rotate([0, 0, r]) translate([0, 32.5, -36]) linear_extrude(height = 40) circle(d = 6.5);
        for (r = [0, 180])
            rotate([0, 0, r]) translate([-9.25, 27, -36]) linear_extrude(height = 40) square([31, 6], center=true);
        for (r = [0, 180])
            rotate([0, 0, r]) translate([3, 29, -36]) linear_extrude(height = 20) square([4, 6], center=true);

        for (r = [0, 180])
            rotate([0, 0, r]) translate([-1, 35, -50]) linear_extrude(height = 15) square([17, 20], center=true);

        rotate([0, 0, 0]) translate([-35, 0, -80]) linear_extrude(height = 100) square([10, 80], center=true);
        rotate([0, 0, 0]) translate([37, 0, -80]) linear_extrude(height = 100) square([10, 80], center=true);

        rotate([0, 0, 0]) translate([35, 0, -20]) linear_extrude(height = 14) square([10, 64], center=true);

        rotate([0, 0, 0]) translate([28, 0, -5]) linear_extrude(height = 6) square([10, 43], center=true);
        rotate([0, 0, 0]) translate([-28, 16, -4]) linear_extrude(height = 5) square([10, 10], center=true);
        rotate([0, 0, 0]) translate([-28, -.5, -5]) linear_extrude(height = 6) square([10, 12], center=true);
        rotate([0, 0, 90]) translate([-36, -18.75, -5]) linear_extrude(height = 6) square([35, 17], center=true);
        rotate([0, 0, 270]) translate([-36, 15.75, -5]) linear_extrude(height = 6) square([30, 9], center=true);


        rotate([0, 0, 0]) translate([30, 32.5, -5]) linear_extrude(height = 6) circle(d = 1.8);
        rotate([0, 0, 0]) translate([30, -32.5, -5]) linear_extrude(height = 6) circle(d = 1.8);
        rotate([0, 0, 0]) translate([-27.5, 35.5, -5]) linear_extrude(height = 6) circle(d = 1.8);
        rotate([0, 0, 0]) translate([-27.5, -35.5, -5]) linear_extrude(height = 6) circle(d = 1.8);

        rotate([0, 90, 0]) translate([39.5, 35.5, 27]) linear_extrude(height = 6) circle(d = 1.8);
        rotate([0, 90, 0]) translate([39.5, -35.5, 27]) linear_extrude(height = 6) circle(d = 1.8);
        rotate([0, 90, 0]) translate([2.5, 35.5, 27]) linear_extrude(height = 6) circle(d = 1.8);
        rotate([0, 90, 0]) translate([2.5, -35.5, 27]) linear_extrude(height = 6) circle(d = 1.8);
    }
}

