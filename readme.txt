lights_camera
>> A basic opengl lighting example by Pete Werner 2013 https://github.com/petewerner/generative/tree/master/lights_camera and this is working on 0.8.4

lightTest1
>> test about specular light

lightTest2
>> test about basic light features and culling

lightTest3
>> test about directional light and setOrientation

lightTest4
>> test to compare three light types which are point light, spot light, and directional light

lightTest5
>> test about the balance between diffuse light, specular light, and ambient light and check how it looks with different resolution of sphere. each value can be changed with GUI

lightTest6
>> test about attenuation of light and you can change each attenuation factor which are constant, linear, and quadratic with GUI

lightTest7
>> test about lighting for 3d model which include plane type model, non-plane type model and low polygon model. You can check smoothLighting and separateSpecularLight, and you can enable/disable both of them with GUI.

lightTest8
>> test about specular color, diffuse color,and ambient color for light VS specular color, diffuse color,and ambient color for material(I found a bug about glEnable(GL_COLOR_MATERIAL), see line 98 in ofApp.cpp to check about this and I commented out all code about it) Git issue about this is here https://github.com/yutatoga/lightTest/issues/1