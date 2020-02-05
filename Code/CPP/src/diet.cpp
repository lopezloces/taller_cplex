#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"
#include <cstdio>
#include <vector>
#include <sstream>

using rapidjson::Value;
using std::endl;
using std::cerr;

IloNumArray getDataArray(const Value& data,
                         IloEnv env,
                         int size)
{
    IloNumArray array(env, size);
    int k = 0;
    for(auto& c : data.GetArray()){
        array[k] = c.GetDouble();
        k++;
    }
    return array;
}

IloNumArray2 getDataMatrix(const Value& data,
                           IloEnv env,
                           int sizex,
                           int sizey)
{
    IloNumArray2 array(env, sizex);
    int k = 0;
    for(auto& f : data.GetArray()){
        array[k] = getDataArray(f, env, sizey);
        k++;
    }
    return array;
}

int main(int argc, char **argv)
{
    
    try {
        std::string filename = argv[1];
        
        FILE* archivo = fopen(filename.c_str(), "r");
        
        char read_buffer[65536];
        
        rapidjson::FileReadStream is(archivo, read_buffer, sizeof(read_buffer));
        
        rapidjson::Document d;
        d.ParseStream(is);
        
        int nutrientes = d["nutrientes"].GetInt();
        int comidas = d["comidas"].GetInt();
        
        const Value& cc = d["costo_comida"];
        
        const Value& cm = d["comida_minima"];
        
        const Value& cma = d["comida_maxima"];
        
        const Value& nm = d["nutr_minimo"];
        
        const Value& nma = d["nutr_maximo"];
        
        const Value& nc = d["nutr_comida"];
        
        fclose(archivo);
        
    catch (...) {
        cerr << "Error " << endl;
    }
    
    env.end();
    
    return 0;
}
