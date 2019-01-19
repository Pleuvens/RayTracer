#pragma once

#include "../utils/color.hh"

class Material
{
    public:
        Material();
        Material(Color ka_, Color kd_, Color ks_, 
        float ns_, float ni_, float nr_, float d_);

        Color getKa() const;
        Color getKd() const;
        Color getKs() const;
        float getNs() const;
        float getNi() const;
        float getNr() const;
        float getD() const;

        void setKa(const Color& ka_);
        void setKd(const Color& kd_);
        void setKs(const Color& ks_);
        void setNs(const float& ns_);
        void setNi(const float& ni_);
        void setNr(const float& nr_);
        void setD(const float& d_);

    protected:
        Color ka;
        Color kd;
        Color ks;

        float ns;
        float ni;
        float nr;
        float d;
};