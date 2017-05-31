#ifndef RENDERABLE_H
#define RENDERABLE_H
#include <vector>
#include "kf/kf_vector.h"
#include "kf/kf_ray.h"
#include "material.h"

class Renderable;

class HitPoint
{
public:
	HitPoint() :m_distance(0), m_hit(false), m_renderable(0)
	{
	}
	void nearest(const HitPoint &hp);
	kf::Vector3 m_normal;
	kf::Vector3 m_tangent;
	kf::Vector3 m_binormal;
	kf::Vector3 m_position;
	kf::Ray m_ray;
	float m_distance;
	bool m_hit;
	Renderable *m_renderable;
};

class Renderable
{
public:
	Renderable(float rad = 1.0f);
	HitPoint intersect(const kf::Ray &ray);
	kf::Vector3 m_position;
	float m_radius;
	Material m_material;
};

#endif
