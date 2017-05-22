class Shape2D:
    def square(self):
        return 0.0
    
    def perimeter(self):
        return 0.0
    
    def __str__(self):
        return "Shape2D"

class Shape3D:
    def volume(self):
        return 0.0
    
    def __str__(self):
        return "Shape3D"

class Rectangle(Shape2D):
    __width = 0.0
    __height = 0.0
    
    def __init__(self, width, height):
        self.__width = width
        self.__height = height
        
    def square(self):
        return self.__width * self.__height
    
    def __str__(self):
        return "Rectangle {0}x{1}".format(self.__width, self.__height)

class Circle(Shape2D):
    __radius = 0.0
    
    def __init__(self, radius):
        self.__radius = radius
    
    def square(self):
        return self.__radius * self.__radius * 3.14159265359
    
    def __str__(self):
        return "Circle r={0}".format(self.__radius)

class Sphere(Shape3D):
    __radius = 0.0
    
    def __init__(self, radius):
        self.__radius = radius
    
    def volume(self):
        return 4.0 * 3.14159265359 * self.__radius * self.__radius * self.__radius / 3.0
    
    def __str__(self):
        return "Sphere r={0}".format(self.__radius)

class Cylinder(Shape3D):
    __height = 0.0
    __circle = None
    
    def __init__(self, radius, height):
        self.__circle = Circle(radius)
        self.__height = height
    
    def volume(self):
        return self.__circle.square() * self.__height


""" using classes """

flatShapes = [Rectangle(10.0, 5.0), Circle(5.0), Rectangle(7.0, 3.0), Circle(15.0), Rectangle(10.0, 23.0)]
threeDimensionalShapes = [Sphere(1.0), Sphere(3.0), Cylinder(3.0, 3.0), Cylinder(5.0, 10.0)]

for shape in flatShapes:
    print(shape)
    print("\t with square {0}".format(shape.square()))
    print("")

print("")

for shape in threeDimensionalShapes:
    print(shape)
    print("\t with volume {0}".format(shape.volume()))
    print("")