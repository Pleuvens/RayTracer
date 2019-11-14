#ifdef _TESTS

#include <vector>

#include "intersection.hh"
#include "op_overloading.hh"
#include "catch.hpp"

TEST_CASE("INTERSECTION: encapsulates t and object", "[multi-file:intersection]")
{
    Sphere s;
    Intersection i(3.5, std::make_shared<Sphere>(s));
    REQUIRE(isEqual(i.getT(), 3.5));
    REQUIRE(i.getObject() == s);
}

TEST_CASE("INTERSECTION: Aggregating intersections", "[multi-file:intersection]")
{
    Sphere s;
    Intersection i1(1, std::make_shared<Sphere>(s));
    Intersection i2(2, std::make_shared<Sphere>(s));
    std::vector<Intersection> xs = Intersection::intersections({i1, i2});
    REQUIRE(xs.size() == 2);
    REQUIRE(isEqual(xs[0].getT(), 1));
    REQUIRE(isEqual(xs[1].getT(), 2));
}

TEST_CASE("INTERSECTION: The hit, when all intersections have positive t",
        "[multi-file:intersection]")
{
    Sphere s;
    Intersection i1(1, std::make_shared<Sphere>(s));
    Intersection i2(2, std::make_shared<Sphere>(s));
    auto xs = Intersection::intersections({i2, i1});
    auto i = Intersection::hit(xs);
    REQUIRE(i.value() == i1);
}

TEST_CASE("INTERSECTION: The hit, when some intersections have negative t",
        "[multi-file:intersection]")
{
    Sphere s;
    Intersection i1(-1, std::make_shared<Sphere>(s));
    Intersection i2(1, std::make_shared<Sphere>(s));
    auto xs = Intersection::intersections({i2, i1});
    auto i = Intersection::hit(xs);
    REQUIRE(i.value() == i2);
}

TEST_CASE("INTERSECTION: The hit, when all intersections have negative t",
        "[multi-file:intersection]")
{
    Sphere s;
    Intersection i1(-2, std::make_shared<Sphere>(s));
    Intersection i2(-1, std::make_shared<Sphere>(s));
    auto xs = Intersection::intersections({i2, i1});
    auto i = Intersection::hit(xs);
    REQUIRE(i == std::nullopt);
}

TEST_CASE("INTERSECTION: The hit is always the lowest nonnegative intersection",
        "[multi-file:intersection]")
{
    Sphere s;
    Intersection i1(5, std::make_shared<Sphere>(s));
    Intersection i2(7, std::make_shared<Sphere>(s));
    Intersection i3(-3, std::make_shared<Sphere>(s));
    Intersection i4(2, std::make_shared<Sphere>(s));
    auto xs = Intersection::intersections({i1, i2, i3, i4});
    auto i = Intersection::hit(xs);
    REQUIRE(i.value() == i4);
}

TEST_CASE("INTERSECTION: Finding n1 and n2 at various intersections",
        "[multi-file:intersection]")
{
    Sphere A = Sphere::glassSphere();
    A.setTransform(Matrix::scaling(2, 2, 2));
    Sphere B = Sphere::glassSphere();
    B.setTransform(Matrix::translation(0, 0, -0.25));
    Material b_mat;
    b_mat.setRefractiveIndex(2);
    B.setMaterial(b_mat);
    Sphere C = Sphere::glassSphere();
    C.setTransform(Matrix::translation(0, 0, 0.25));
    Materiel c_mat;
    c_mat.setRefractiveIndex(2.5);
    C.setMaterial(c_mat);
    Ray r(Point(0, 0, -4), Vector(0, 0, 1));
    Intersection i1(2, std::make_shared<Sphere>(A));
    Intersection i2(2.75, std::make_shared<Sphere>(B));
    Intersection i3(3.25, std::make_shared<Sphere>(C));
    Intersection i4(4.75, std::make_shared<Sphere>(B));
    Intersection i5(5.25, std::make_shared<Sphere>(C));
    Intersection i6(6, std::make_shared<Sphere>(A));
    auto xs = Intersection::intersections({i1, i2, i3, i4, i5, i6});
    auto comps1 = r.prepareComputations(xs[0], xs);
    auto comps2 = r.prepareComputations(xs[1], xs);
    auto comps3 = r.prepareComputations(xs[2], xs);
    auto comps4 = r.prepareComputations(xs[3], xs);
    auto comps5 = r.prepareComputations(xs[4], xs);
    auto comps6 = r.prepareComputations(xs[5], xs);
    REQUIRE(isEqual(comps1.getN1(), 1));
    REQUIRE(isEqual(comps1.getN2(), 1.5));
    REQUIRE(isEqual(comps2.getN1(), 1.5));
    REQUIRE(isEqual(comps2.getN2(), 2));
    REQUIRE(isEqual(comps3.getN1(), 2));
    REQUIRE(isEqual(comps3.getN2(), 2.5));
    REQUIRE(isEqual(comps4.getN1(), 2.5));
    REQUIRE(isEqual(comps4.getN2(), 2.5));
    REQUIRE(isEqual(comps5.getN1(), 2.5));
    REQUIRE(isEqual(comps5.getN2(), 1.5));
    REQUIRE(isEqual(comps6.getN1(), 1.5));
    REQUIRE(isEqual(comps6.getN2(), 1));
}

TEST_CASE("INTERSECTION: The under point is offset below the surface",
        "[multi-file:intersection]")
{
    Ray r(Point(0, 0, -5), Vector(0, 0, 1));
    Sphere shape = Sphere::glassSphere();
    shape.setTransform(Matrix::translation(0, 0, 1));
    Intersection i(5, std::make_shared<Sphere>(shape));
    auto xs = Intersection::intersections({ i });
    auto comps = r.prepareComputations(i, xs);
    REQUIRE(comps.getUnderPoint().getZ() > EPSILON / 2);
    REQUIRE(comps.getPoint().getZ() < comps.getUnderPoint().getZ());
}

#endif
