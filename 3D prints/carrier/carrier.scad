
// color(c = "#000088")  rotate([180, 0, 0]) translate([-110, -110, 0]) import("base.stl");
$fn = 100; 

rotate([0, 0, 0]) translate([25, -13, -13]) linear_extrude(height = 12) square([2, 6]);
rotate([0, 0, 90]) translate([25, -13, -13]) linear_extrude(height = 12) square([2, 6]); 
rotate([0, 0, 180]) translate([25, -13, -13]) linear_extrude(height = 12) square([2, 6]); 
rotate([0, 0, 270]) translate([25, -13, -13]) linear_extrude(height = 12) square([2, 6]); 



difference() {
    union() {
        translate([0, 0, -3]) linear_extrude(height = 3) square([60, 76], center=true);
        rotate([0, 0, 0]) translate([0, -32.5, -30]) linear_extrude(height = 30) circle(d = 10);
        rotate([0, 0, 180]) translate([0, -32.5, -30]) linear_extrude(height = 30) circle(d = 10);
        // translate([0, 32.5, -30]) linear_extrude(height = 30) circle(d = 10);
    }

    union() {
        translate([0, 0, -4]) linear_extrude(height = 6) square([50, 50], center=true);
        rotate([0, 0, 0]) translate([0, 32.5, -32]) linear_extrude(height = 36) circle(d = 6);
        rotate([0, 0, 180]) translate([0, 32.5, -32]) linear_extrude(height = 36) circle(d = 6);
        // translate([0, -32.5, -32]) linear_extrude(height = 36) circle(d = 6);
        rotate([0, 0, 0]) translate([-9, 27, -32]) linear_extrude(height = 34) square([32, 6], center=true);
        rotate([0, 0, 180]) translate([-9, 27, -32]) linear_extrude(height = 34) square([32, 6], center=true);

    }
}

