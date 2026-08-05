
// color(c = "#000088")  rotate([180, 0, 0]) translate([-110, -110, 0]) import("base.stl");
$fn = 100; 

rotate([0, 0, 0]) translate([25, -12.5, -19.5]) linear_extrude(height = 18) square([2, 6]);
rotate([0, 0, 90]) translate([25, -12.5, -19.5]) linear_extrude(height = 18) square([2, 6]); 
rotate([0, 0, 180]) translate([25, -12.5, -19.5]) linear_extrude(height = 18) square([2, 6]); 
rotate([0, 0, 270]) translate([25, -12.5, -19.5]) linear_extrude(height = 18) square([2, 6]); 

rotate([0, 0, 0]) translate([25, -12.5, -12]) linear_extrude(height = 8) square([5, 6]);
rotate([0, 0, 90]) translate([25, -12.5, -12]) linear_extrude(height = 8) square([5, 6]);
rotate([0, 0, 180]) translate([25, -12.5, -12]) linear_extrude(height = 8) square([5, 6]);
rotate([0, 0, 270]) translate([25, -12.5, -12]) linear_extrude(height = 8) square([5, 6]);


difference() {
    union() {
        translate([0, 0, -6]) linear_extrude(height = 6) square([60, 76], center=true);
        rotate([0, 0, 0]) translate([0, 35, -42]) linear_extrude(height = 42) square([56, 6], center=true);
        rotate([0, 0, 180]) translate([0, 35, -42]) linear_extrude(height = 42) square([56, 6], center=true);
        rotate([0, 0, 0]) translate([0, -32.5, -34]) linear_extrude(height = 34) circle(d = 10);
        rotate([0, 0, 180]) translate([0, -32.5, -34]) linear_extrude(height = 34) circle(d = 10);
    }

    union() {
        translate([0, 0, -8]) linear_extrude(height = 10) square([49.5, 49.5], center=true);
        rotate([0, 0, 0]) translate([0, 32.5, -36]) linear_extrude(height = 40) circle(d = 6.5);
        rotate([0, 0, 180]) translate([0, 32.5, -36]) linear_extrude(height = 40) circle(d = 6.5);
        rotate([0, 0, 0]) translate([-9.25, 27, -36]) linear_extrude(height = 40) square([31, 6], center=true);
        rotate([0, 0, 180]) translate([-9.25, 27, -36]) linear_extrude(height = 40) square([31, 6], center=true);

        rotate([0, 0, 0]) translate([0, 35, -50]) linear_extrude(height = 16) square([18, 20], center=true);
        rotate([0, 0, 180]) translate([0, 35, -50]) linear_extrude(height = 16) square([18, 20], center=true);

    }
}

