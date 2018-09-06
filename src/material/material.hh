#pragma once

#include "../utils/color.hh"

class Material
{
    public:

        Material(Color ka_, Color kd_, Color ks_, 
        float ns_, float ni_, float nr_, float d_);

        Color getKa();
        Color getKd();
        Color getKs();
        float getNs();
        float getNi();
        float getNr();
        float getD();

        void setKa(Color ka_);
        void setKd(Color kd_);
        void setKs(Color ks_);
        void setNs(float ns_);
        void setNi(float ni_);
        void setNr(float nr_);
        void setD(float d_);

    protected:
        Color ka;
        Color kd;
        Color ks;

        float ns;
        float ni;
        float nr;
        float d;
};