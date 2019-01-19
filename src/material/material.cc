#include "material.hh"

Material::Material(Color ka_, Color kd_, Color ks_, 
        float ns_, float ni_, float nr_, float d_)
{
    ka = ka_;
    kd = kd_;
    ks = ks_;
    ns = ns_;
    ni = ni_;
    nr = nr_;
    d = d_;
}

Color Material::getKa() const
{
    return ka;
}

Color Material::getKd() const
{
    return kd;
}

Color Material::getKs() const
{
    return ks;
}

float Material::getNs() const
{
    return ns;
}

float Material::getNi() const
{
    return ni;
}

float Material::getNr() const
{
    return nr;
}

float Material::getD() const
{
    return d;
}

void Material::setKa(const Color& ka_)
{
    ka = ka_;
}

void Material::setKd(const Color& kd_)
{
    kd = kd_;
}

void Material::setKs(const Color& ks_)
{
    ks = ks_;
}

void Material::setNs(const float& ns_)
{
    ns = ns_;
}

void Material::setNi(const float& ni_)
{
    ni = ni_;
}

void Material::setNr(const float& nr_)
{
    nr = nr_;
}

void Material::setD(const float& d_)
{
    d = d_;
}