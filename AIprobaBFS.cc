#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME probaBFS


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
  typedef vector<vector<Pos>>vector_posicio;
  typedef map <Pos,bool> visited;
  typedef vector<vector<int>>Matrix;
  vector<Dir> dirs = {Bottom, BR, Right , RT, Top, TL, Left , LB};
  
//per a buscar gemes
  Dir gems(Pos a){
    Pos previ = a;
    queue <Pos> cua;
    queue<Pos>posicio_inicial;
    int inf = 777777777;
    vector<vector<int>>dist(40, vector<int>(80, inf));
    cua.push(a);
    dist[a.i][a.j] = 0;

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

        //Esquerra
        if (pos_ok(esq) and dist[esq.i][esq.j] == inf and not daylight(esq)){
          Cell actual = cell(esq);
          if (actual.gem) return Left;
          cua.push(esq);
          dist[esq.i][esq.j] = dist[previ.i][previ.j]+1;
        }
          //Dreta
        if (pos_ok(dreta) and dist[dreta.i][dreta.j] == inf and not daylight(dreta)){
          Cell actual = cell(dreta);
          if (actual.gem) return Right;
          cua.push(dreta);
          dist[dreta.i][dreta.j] = dist[previ.i][previ.j]+1;
        }

          //Dalt
        if (pos_ok(adalt) and dist[adalt.i][adalt.j] == inf and not daylight(adalt)){
          Cell actual = cell(adalt);
          if (actual.gem) return Top;
          cua.push(adalt);
          dist[adalt.i][adalt.j] = dist[previ.i][previ.j]+1;
        }

          //Baix
        if (pos_ok(baix) and dist[baix.i][baix.j] == inf and not daylight(baix)){
          Cell actual = cell(baix);
          if (actual.gem) return Bottom;
          cua.push(baix);
          dist[baix.i][baix.j] = dist[previ.i][previ.j]+1;
        }

        //Top left
        if (pos_ok(de) and dist[de.i][de.j] == inf and not daylight(de)){
          Cell actual = cell(de);
          if (actual.gem) return TL;
          cua.push(de);
          dist[de.i][de.j] = dist[previ.i][previ.j]+1;
        }
        
            //Top Right
        if (pos_ok(dd) and dist[dd.i][dd.j] == inf and not daylight(dd)){
          Cell actual = cell(dd);
          if (actual.gem) return RT;
          cua.push(dd);
          dist[dd.i][dd.j] = dist[previ.i][previ.j]+1;
        }
            //Bottom left
        if (pos_ok(be) and dist[be.i][be.j] == inf and not daylight(be)){
          Cell actual = cell(be);
          if (actual.gem) return LB;
          cua.push(be);
          dist[be.i][be.j] = dist[previ.i][previ.j]+1;
        }
            //Bttom rigth
        if (pos_ok(bd) and dist[bd.i][bd.j] == inf and not daylight(bd)){
          Cell actual = cell(bd);
          if (actual.gem) return BR;
          cua.push(bd);
          dist[bd.i][bd.j] = dist[previ.i][previ.j]+1;
        }
        previ = actu;
        

    }
    return None;
    }
   
  //Per moure's per underground
  Dir escombra(Pos a){
    Pos previ = a;
    queue <Pos> cua;
    queue<Pos>posicio_inicial;
    int inf = 777777777;
    vector<vector<int>>dist(40, vector<int>(80, inf));
    cua.push(a);
    dist[a.i][a.j] = 0;
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


      //Esquerra
      if (pos_ok(esq) and dist[esq.i][esq.j] == inf){
        Cell actual = cell(esq);
        if (actual.owner == -1 and actual.type != Rock) return Left;
        cua.push(esq);
        dist[esq.i][esq.j] = dist[previ.i][previ.j]+1;
      }
        //Dreta
      if (pos_ok(dreta) and dist[dreta.i][dreta.j] == inf){
        Cell actual = cell(dreta);
        if (actual.owner == -1 and actual.type != Rock) return Right;
        cua.push(dreta);
        dist[dreta.i][dreta.j] = dist[previ.i][previ.j]+1;
      }

        //Dalt
      if (pos_ok(adalt) and dist[adalt.i][adalt.j] == inf){
        Cell actual = cell(adalt);
        if (actual.owner == -1 and actual.type != Rock) return Top;
        cua.push(adalt);
        dist[adalt.i][adalt.j] = dist[previ.i][previ.j]+1;
      }

        //Baix
      if (pos_ok(baix) and dist[baix.i][baix.j] == inf){
        Cell actual = cell(baix);
        if (actual.owner == -1 and actual.type != Rock) return Bottom;
        cua.push(baix);
        dist[baix.i][baix.j] = dist[previ.i][previ.j]+1;
      }

      //Top left
      if (pos_ok(de) and dist[de.i][de.j] == inf){
        Cell actual = cell(de);
        if (actual.owner == -1 and actual.type != Rock) return TL;
        cua.push(de);
        dist[de.i][de.j] = dist[previ.i][previ.j]+1;
      }
      
          //Top Right
      if (pos_ok(dd) and dist[dd.i][dd.j] == inf){
        Cell actual = cell(dd);
        if (actual.owner == -1 and actual.type != Rock) return RT;
        cua.push(dd);
        dist[dd.i][dd.j] = dist[previ.i][previ.j]+1;
      }
          //Bottom left
      if (pos_ok(be) and dist[be.i][be.j] == inf){
        Cell actual = cell(be);
        if (actual.owner == -1 and actual.type != Rock) return LB;
        cua.push(be);
        dist[be.i][be.j] = dist[previ.i][previ.j]+1;
      }
          //Bttom right
      if (pos_ok(bd) and dist[bd.i][bd.j] == inf){
        Cell actual = cell(bd);
        if (actual.owner == -1 and actual.type != Rock) return BR;
        cua.push(bd);
        dist[bd.i][bd.j] = dist[previ.i][previ.j]+1;
      }
      previ = actu;
      

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
    Pos previ = a;
    queue <Pos> cua;
    queue<Pos>posicio_inicial;
    int inf = 777777777;
    vector<vector<int>>dist(40, vector<int>(80, inf));
    cua.push(a);
    dist[a.i][a.j] = 0;

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

      //Esquerra
      if (pos_ok(esq) and dist[esq.i][esq.j] == inf){
        if (buscar_enemic(cell(esq))) return Left;
        cua.push(esq);
        dist[esq.i][esq.j] = dist[previ.i][previ.j]+1;
      }

        //Dreta
      if (pos_ok(dreta) and dist[dreta.i][dreta.j] == inf){
        if (buscar_enemic(cell(dreta)) ) return Right;
        cua.push(dreta);
        dist[dreta.i][dreta.j] = dist[previ.i][previ.j]+1;
      }

        //Dalt
      if (pos_ok(adalt) and dist[adalt.i][adalt.j] == inf){
        if (buscar_enemic(cell(adalt))) return Top;
        cua.push(adalt);
        dist[adalt.i][adalt.j] = dist[previ.i][previ.j]+1;
      }

        //Baix
      if (pos_ok(baix) and dist[baix.i][baix.j] == inf){
        if (buscar_enemic(cell(baix))) return Bottom;
        cua.push(baix);
        dist[baix.i][baix.j] = dist[previ.i][previ.j]+1;
      }

      //Top left
      if (pos_ok(de) and dist[de.i][de.j] == inf ){
        if (buscar_enemic(cell(de))) return TL;
        cua.push(de);
        dist[de.i][de.j] = dist[previ.i][previ.j]+1;
      }
      
          //Top Right
      if (pos_ok(dd) and dist[dd.i][dd.j] == inf){
        if (buscar_enemic(cell(dd))) return RT;
        cua.push(dd);
        dist[dd.i][dd.j] = dist[previ.i][previ.j]+1;
      }
          //Bottom left
      if (pos_ok(be) and dist[be.i][be.j] == inf ){
        if (buscar_enemic(cell(be))) return LB;
        cua.push(be);
        dist[be.i][be.j] = dist[previ.i][previ.j]+1;
      }
          //Bttom rigth
      if (pos_ok(bd) and dist[bd.i][bd.j] == inf){
        if (buscar_enemic(cell(bd))) return BR;
        cua.push(bd);
        dist[bd.i][bd.j] = dist[previ.i][previ.j]+1;
      }
      previ = actu;

  }
  return None;    
  }

  void move_pioneer(int id){
    Unit pio = unit(id);
    Pos pio_pos = pio.pos;
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