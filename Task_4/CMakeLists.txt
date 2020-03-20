cmake_minimum_required(VERSION 3.14)
project(Task_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task_4 main.cpp figures/Rectangle.cpp figures/Rectangle.h util/system.cpp util/system.h figures/Circle.cpp figures/Circle.h figures/abstract/Vector2D.cpp figures/abstract/Vector2D.h figures/abstract/Figure.h figures/abstract/PhysObject.h figures/abstract/PhysObject.cpp figures/abstract/interfases/IGeoFig.h figures/abstract/interfases/IPhysObject.h figures/abstract/interfases/IDialogInitiable.h figures/abstract/interfases/BaseCObject.h figures/abstract/interfases/CVector2D.h figures/abstract/interfases/IPrintable.h)