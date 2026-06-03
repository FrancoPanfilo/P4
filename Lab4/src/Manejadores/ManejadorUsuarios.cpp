#include "../../include/Manejadores/ManejadorUsuarios.h"

std::set<DTUsuario> ManejadorUsuarios::listarUsuarios() {
    std::set<DTUsuario> resultado;
    for (std::pair<std::string, Usuario*> par : usuarios) {
        Usuario* u = par.second;
        resultado.insert(DTUsuario(u->getNickname(), u->getNombre()));
    }
    return resultado;
}
