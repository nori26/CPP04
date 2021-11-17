C++ 98にはインターフェイスはありませんが、純粋な抽象クラスをインターフェイスと呼ぶのは一般的です。 最後の演習では、インターフェイスを試してみましょう。 AMateriaクラスを完成させ、必要なメンバ関数を実装してください。

    class AMateria {
 protected:
  std::string type;
  // [...]
 public:
  AMateria(std::string const& type);
  // [...]
  std::string const& getType() const;  //マテリアのタイプを返します。
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

Create the concrete Materias
具象マテリアである Ice と Cure を作成します。タイプは名前を小文字にしたものになります（Iceなら "ice"）。
clone()メソッドは、もちろん実際のマテリアのタイプのインスタンスを返します。
(return a new instance of the real Materia’s type.)

use(ICharacter&) メソッドについては、以下のように表示されます。

 - Ice: "* NAMEにアイスボルトを放つ *"
 - Cure: "* NAMEの傷を癒す *"

 (NAMEはパラメータとして与えられたキャラクターの名前）
 マテリアを別のマテリアに割り当てる際、タイプをコピーしては意味がありません。

以下のインターフェイスを実装したCharacterクラスを作成します。

class ICharacter
{
 public:
  virtual ~ICharacter() {}
  virtual std::string const& getName() const = 0;
  virtual void equip(AMateria * m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter& target) = 0;
};


キャラクターは最大で4つのマテリアのインベントリを持っており、最初は空っぽである。
スロット0～3のマテリアを順に装備していく。
インベントリが満杯の状態でマテリアを装備しようとしたり、存在しないマテリアを使用・装備解除しようとしたりしても、何もしない。
unequipメソッドは、Materiaを削除してはいけません。
use(int, ICharacter&) メソッドは、idxスロットのMateriaを使用し、AMateria::useメソッドのパラメータとしてtargetを渡す必要があります。

キャラクターのインベントリにあるすべてのAMateriaをサポートできるようにしなければなりません。
キャラクターには、名前をパラメータとして受け取るコンストラクタが必要です。
Characterのコピーや代入も可能でなければなりません。
キャラクターの古いマテリアは削除しなければなりません。キャラクタの破壊時にも同様です。

MateriaSourceクラスを作成します。
MateriaSourceクラスは以下のインターフェイスを実装する必要があります。


class IMateriaSource
{
 public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria*) = 0;
  virtual AMateria* createMateria(std::string const& type) = 0;
};

learnMateriaは、パラメータとして渡されたMateriaをコピーしてメモリに保存し、後でクローンを作成する必要がある。
createMateria(std::string const &)は新しいMateriaを返しますが、このMateriaはパラメータと同じタイプのMateriaをコピーしたものです。
タイプが不明な場合は0を返します。

SourceはMateriaの「テンプレート」を学習し、必要に応じて再作成することができなければなりません。
そうすれば、マテリアの「本当の」タイプを知らなくても、それを識別する文字列だけでマテリアを作ることができるようになります。
