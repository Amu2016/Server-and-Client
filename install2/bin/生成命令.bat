protoc test.proto --cpp_out=./

protoc –plugin=/usr/local/bin/protoc-gen-objc *.proto cpp_out="./"

[libprotobuf WARNING D:\Cocos\Server-and-Client\protobuf-3.6.1\src\google\protob
uf\compiler\parser.cc:562] No syntax specified for the proto file: test.proto. P
lease use 'syntax = "proto2";' or 'syntax = "proto3";' to specify a syntax versi
on. (Defaulted to proto2 syntax.)

D:\Cocos\Server-and-Client\install2\bin>protoc test.proto --cpp_out=./
test.proto:7:13: Explicit 'optional' labels are disallowed in the Proto3 syntax.
 To define 'optional' fields in Proto3, simply remove the 'optional' label, as f
ields are 'optional' by default.

 Required fields are not allowed in proto3
 

#ifdef GL_ES
precision lowp float;
#endif

varying vec4 v_fragmentColor;

void main()
{
    gl_FragColor = v_fragmentColor;
}
