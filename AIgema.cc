#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME gema


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */
  typedef vector<int> Vect;

  typedef map <Pos,bool> visited;

  map<int, Dir> mapa_de_prioritat;


  
//per a buscar gemes
  Dir gems(Pos a){
      queue <Pos> cua;
      visited vis;
      queue <int> distancia;

      cua.push(a);
      distancia.push(0);
      vis.insert(make_pair(a, true));

      while (!cua.empty()){
        Pos actu = cua.front();
        cua.pop();
        Pos esq = actu + Left;
        Pos dreta = actu + Right;
        Pos adalt = actu + Top;
        Pos baix = actu + Bottom;
        Pos de = actu + TL;
        Pos dd = actu + RT;
        Pos be = actu + LB;
        Pos bd = actu + BR;

        auto it = vis;
        //Esquerra
        if (pos_ok(esq) and not_visited_yet(esq, vis) and not daylight(esq)){
          Cell actual = cell(esq);
          if (actual.gem) return Left;
          cua.push(esq);
          distancia.push(distancia.front()+1);
          vis.insert(make_pair(esq, true));
        }
          //Dreta
        if (pos_ok(dreta) and not_visited_yet(dreta, vis) and not daylight(dreta)){
          Cell actual = cell(dreta);
          if (actual.gem) return Right;
          cua.push(dreta);
          distancia.push(distancia.front()+1);
          vis.insert(make_pair(dreta, true));
        }

          //Dalt
        if (pos_ok(adalt) and not_visited_yet(adalt, vis) and not daylight(adalt)){
          Cell actual = cell(adalt);
          if (actual.gem) return Top;
          cua.push(adalt);
          distancia.push(distancia.front()+1);
          vis.insert(make_pair(adalt, true));
        }

          //Baix
        if (pos_ok(baix) and not_visited_yet(baix, vis) and not daylight(baix)){
          Cell actual = cell(baix);
          if (actual.gem) return Bottom;
          cua.push(baix);
          distancia.push(distancia.front()+1);
          vis.insert(make_pair(baix, true));
        }

        //Top left
        if (pos_ok(de) and not_visited_yet(de, vis) and not daylight(de)){
          Cell actual = cell(de);
          if (actual.gem) return TL;
          cua.push(de);
          distancia.push(distancia.front()+1);
          vis.insert(make_pair(de, true));
        }
        
            //Top Right
        if (pos_ok(dd) and not_visited_yet(dd, vis) and not daylight(dd)){
          Cell actual = cell(dd);
          if (actual.gem) return RT;
          cua.push(dd);
          distancia.push(distancia.front()+1);
          vis.insert(make_pair(dd, true));
        }
            //Bottom left
        if (pos_ok(be) and not_visited_yet(be, vis) and not daylight(be)){
          Cell actual = cell(be);
          if (actual.gem) return LB;
          cua.push(be);
          distancia.push(distancia.front()+1);
          vis.insert(make_pair(be, true));
        }
            //Bttom rigth
        if (pos_ok(bd) and not_visited_yet(bd, vis) and not daylight(bd)){
          Cell actual = cell(bd);
          if (actual.gem) return BR;
          cua.push(bd);
          distancia.push(distancia.front()+1);
          vis.insert(make_pair(bd, true));
        }
        

    }
    return None;
    }
   
  //per mirar si s'ha visitat aquella posició
  bool not_visited_yet(Pos a, visited& b){
      auto it = b.find(a);
      if (it == b.end()) return true;
      return false;
  }

  //Per moure's per underground
  Dir escombra(Pos a){
    queue <Pos> cua;
    visited vis;
    queue <int> distancia;

    cua.push(a);
    distancia.push(0);
    vis.insert(make_pair(a, true));
    while (!cua.empty()){
      Pos actu = cua.front();
      cua.pop();
      Pos esq = actu + Left;
      Pos dreta = actu + Right;
      Pos adalt = actu + Top;
      Pos baix = actu + Bottom;
      Pos de = actu + TL;
      Pos dd = actu + RT;
      Pos be = actu + LB;
      Pos bd = actu + BR;

      auto it = vis;

      if (cell(actu).type == Elevator and round()>90) return Up;
      //Esquerra
      if (pos_ok(esq) and not_visited_yet(esq, vis)){
        Cell actual = cell(esq);
        if (actual.owner == -1 and actual.type != Rock) return Left;
        cua.push(esq);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(esq, true));
      }
        //Dreta
      if (pos_ok(dreta)){
        Cell actual = cell(dreta);
        if (actual.owner == -1 and actual.type != Rock) return Right;
        cua.push(dreta);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(dreta, true));
      }

        //Dalt
      if (pos_ok(adalt)){
        Cell actual = cell(adalt);
        if (actual.owner == -1 and actual.type != Rock) return Top;
        cua.push(adalt);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(adalt, true));
      }

        //Baix
      if (pos_ok(baix)){
        Cell actual = cell(baix);
        if (actual.owner == -1 and actual.type != Rock) return Bottom;
        cua.push(baix);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(baix, true));
      }

      //Top left
      if (pos_ok(de)){
        Cell actual = cell(de);
        if (actual.owner == -1 and actual.type != Rock) return TL;
        cua.push(de);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(de, true));
      }
      
          //Top Right
      if (pos_ok(dd) ){
        Cell actual = cell(dd);
        if (actual.owner == -1 and actual.type != Rock) return RT;
        cua.push(dd);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(dd, true));
      }
          //Bottom left
      if (pos_ok(be) ){
        Cell actual = cell(be);
        if (actual.owner == -1 and actual.type != Rock) return LB;
        cua.push(be);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(be, true));
      }
          //Bttom rigth
      if (pos_ok(bd)){
        Cell actual = cell(bd);
        if (actual.owner == -1 and actual.type != Rock) return BR;
        cua.push(bd);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(bd, true));
      }
      

  }
  return None;
}

  // per mirar si al voltant té un enemic
  bool buscar_enemic (Cell obj){
    int id = obj.id;
    if (id != -1 and unit(id).player != me() and unit(id).player != -1) return true;
    return false; 
    
  }

  //per a fer un atac amb els furyons
  Dir attack (Pos a){
    queue <Pos> cua;
    visited vis;
    queue <int> distancia;

    cua.push(a);
    distancia.push(0);
    vis.insert(make_pair(a, true));

    while (!cua.empty()){
      Pos actu = cua.front();
      cua.pop();
      Pos esq = actu + Left;
      Pos dreta = actu + Right;
      Pos adalt = actu + Top;
      Pos baix = actu + Bottom;
      Pos de = actu + TL;
      Pos dd = actu + RT;
      Pos be = actu + LB;
      Pos bd = actu + BR;

      auto it = vis;

      //Esquerra
      if (pos_ok(esq) and not_visited_yet(esq, vis)){
        if (buscar_enemic(cell(esq))) return Left;
        cua.push(esq);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(esq, true));
      }
        //Dreta
      if (pos_ok(dreta) and not_visited_yet(dreta, vis)){
        if (buscar_enemic(cell(dreta)) ) return Right;
        cua.push(dreta);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(dreta, true));
      }

        //Dalt
      if (pos_ok(adalt) and not_visited_yet(adalt, vis)){
        if (buscar_enemic(cell(adalt))) return Top;
        cua.push(adalt);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(adalt, true));
      }

        //Baix
      if (pos_ok(baix) and not_visited_yet(baix, vis)){
        if (buscar_enemic(cell(baix))) return Bottom;
        cua.push(baix);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(baix, true));
      }

      //Top left
      if (pos_ok(de) and not_visited_yet(de, vis) ){
        if (buscar_enemic(cell(de))) return TL;
        cua.push(de);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(de, true));
      }
      
          //Top Right
      if (pos_ok(dd) and not_visited_yet(dd, vis) ){
        if (buscar_enemic(cell(dd))) return RT;
        cua.push(dd);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(dd, true));
      }
          //Bottom left
      if (pos_ok(be) and not_visited_yet(be, vis) ){
        if (buscar_enemic(cell(be))) return LB;
        cua.push(be);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(be, true));
      }
          //Bttom rigth
      if (pos_ok(bd) and not_visited_yet(bd, vis)){
        if (buscar_enemic(cell(bd))) return BR;
        cua.push(bd);
        distancia.push(distancia.front()+1);
        vis.insert(make_pair(bd, true));
      }
      

  }
  return None;    
  }

  void move_pioneer(int id){
    Unit pio = unit(id);
    Pos pio_pos = pio.pos;
    visited vis;
    Dir direction = None;
    if (pio_pos.k == 1) direction = gems(pio_pos);
    else direction = escombra(pio_pos);
    command (id, direction);
  }

  void movePioneers(Vect& pioneers){
      int size = pioneers.size();
      for (int i = 0; i < size; ++i){
        move_pioneer(pioneers[i]);
      }

  }
  
  void moveFuryan (int id){
    Unit fur = unit(id);
    Pos fur_pos = fur.pos;
    Dir direction = attack(fur_pos);
    
    command (id, direction);
  }

  void movefuryans(Vect& furyans){
    int size = furyans.size();
    for (int i = 0; i < size; ++i) moveFuryan(furyans[i]);
  }

  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
    int jo = me();
    Vect pio = pioneers(jo);
    Vect fur = furyans(jo);


    movePioneers(pio);
    movefuryans(fur);
 
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);