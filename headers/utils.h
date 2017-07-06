#pragma once
#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>
#include <memory>
#include <GL/gl.h>

class SegmentCollider;
class SphereCollider;

std::string loadTextFile(std::string name);
void gl_print_str(std::string name, GLenum _enum);
void gl_info();
void gl_print_extentions();
void gl_check_error();
const char* gl_get_error_string(GLenum err);

bool testIntersection(const SegmentCollider& seg, const SphereCollider& sph) noexcept;
