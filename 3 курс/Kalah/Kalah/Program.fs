// Игра Калах

type Side = Hum | Comp
type Step = { side : Side; row : int }
type Board = BoardConstr of Map<Side , Map<int, int> > | None
type StepInt = Step * int
// Константы положения
let Kalah = 6
let MINDIFF : int = -(6*12) - 1 // среднее значение (разница между моим и калахом компа)
let DEFAULTLVL : int = 4 // чем больше значение тем умнее компьютер
// Начальная доска
let startBoard : Board = 
  let startRow : Map<int, int> = Map.ofList [ (0, 6); (1, 6); (2, 6); (3, 6); (4, 6); (5, 6); (Kalah ,0) ]
  BoardConstr (Map.ofList [ (Comp, startRow); (Hum, startRow)] )
  
// --------         Вспомогательные методы   ---------------


// вернуть значение типа шага
let mStep (s : Side) (r : int) = 
  { side = s; row = r }

// вернуть другую сторону
let difSide (side : Side) = 
  match side with
    | Hum -> Comp
    | Comp -> Hum
// вернуть следующий шаг
let next (step : Step)  = 
  if step.row = Kalah then
    mStep (difSide step.side) 0
  else 
    mStep step.side (step.row + 1)

// вернуть калах этого игрока (Step)
let gKalah (step : Step) =
  { side = step.side; row = Kalah }

// вернуть ячейку напротив (Step) 
let difSideStep (step : Step) =
  if (step.row = Kalah) then
    {side = difSide step.side; row = Kalah}
  else
    {side = difSide step.side; row = Kalah - step.row - 1}

// получить значение ячейки шага
let getN (b : Board) (s : Step) = 
  match b with 
    | None -> 0
    | BoardConstr bb -> bb.[s.side].[s.row]
let getN2 (b : Board) (g : Side) (c : int) = 
  match b with
    | None -> 0
    | BoardConstr bb -> bb.[g].[c]
  
// проверка: пустая ли ячейка
let isEmpty (b : Board) (s : Step) =   
  (getN b s = 0)   

// увеличить на 1
let setInc (b : Board) (s : Step) = 
  match b with
    | None -> None
    | BoardConstr bb ->  let row = bb.[s.side].Add(s.row, (getN b s) + 1)
                         BoardConstr (bb.Add(s.side, row))
// установить ноль
let setZero (b : Board) (s : Step) = 
  match b with 
    | None -> None
    | BoardConstr bb -> let row = bb.[s.side].Add(s.row, 0)
                        BoardConstr (bb.Add(s.side, row))

// увеличить на n
let setIncSome (b : Board) (s : Step) (n : int) =
  match b with 
    | None -> None
    | BoardConstr bb -> let row = bb.[s.side].Add(s.row, (getN b s) + n)
                        BoardConstr (bb.Add(s.side, row))

// Добавляет к калаху игрока камни из напротив стоящей вражеской ячейки и один камень из своей

let takeEnemyScore (b : Board) (s : Step) =
  setZero (setIncSome b (gKalah s) ((getN b (difSideStep s)) + 1)) (difSideStep s)
  

// Доска выигрышная? (на стороне все ячейки пусты)
let isWinBoard (b : Board) (g : Side) =
  let rec ff (b : Board) (step : Step) = 
    if (step.row = Kalah) then
      true
    else
      if (getN b step = 0) then
        ff b (next step)
      else 
        false
  if (ff b (mStep g 0)) then
    true
  else
    false 

// Закончить доску. перенести все камни из ячеек в калах (только для завершенной доски)
let toWinBoard (b : Board) (g : Side) = 
  match isWinBoard b g with
    | false -> b
    | true ->  let rec ff (b : Board) (step : Step) = 
                 if (step.row = Kalah) then
                   b
                 else
                   let n = getN b step
                   if n = 0 then
                     ff b (next step)
                   else
                     ff (setZero (setIncSome b (gKalah step) n) step) (next step)
               ff b (mStep (difSide g) 0)
// окончание игры
let isGameOver (b : Board) = 
  let rec ff (b : Board) (step : Step) = 
    if (step.row = Kalah) then
      true
    else
      if (getN b step = 0) then
        ff b (next step)
      else 
        false
  if (ff b (mStep Hum 0)) || (ff b (mStep Comp 0)) then
    true
  else 
    false
// вывод доски
let printBoard (b : Board) =
  match b with
    | None ->  printfn "------------------------------------------------------------------"
               printfn "Computer's Kalah |  6 |  5 |  4 |  3 |  2 |  1 | Your Kalah|"
               printfn "-----------------+----+----+----+----+----+----+-----------------+"
               printfn "                 +----+----+----+----+----+----+                 +"
               printfn "-----------------+----+----+----+----+----+----+-----------------+"
               printfn "Computer's Kalah | 1  | 2  | 3  |  4 |  5 |  6 | Your Kalah|"
    | _ ->  printfn "------------------------------------------------------------------"
            printfn "Computer's Kalah |  6    5    4    3    2    1 |   Your Kalah    |"
            printfn "-----------------+----+----+----+----+----+----+-----------------+"
            printfn "                 | %2u | %2u | %2u | %2u | %2u | %2u |                 |"
             (getN2 b Comp 5)
             (getN2 b Comp 4)
             (getN2 b Comp 3)
             (getN2 b Comp 2)
             (getN2 b Comp 1)
             (getN2 b Comp 0)
            printfn "      %3u        +----+----+----+----+----+----+      %3u        +"
             (getN2 b Comp Kalah)
             (getN2 b Hum Kalah)
            printfn "                 | %2u | %2u | %2u | %2u | %2u | %2u |                 |"
                (getN2 b Hum 0)
                (getN2 b Hum 1)
                (getN2 b Hum 2)
                (getN2 b Hum 3)
                (getN2 b Hum 4)
                (getN2 b Hum 5)
            printfn "-----------------+----+----+----+----+----+----+-----------------+"
            printfn "Computer's Kalah |  1    2    3    4    5    6 |   Your Kalah    |"
            printfn "-----------------+----+----+----+----+----+----+-----------------+"
//  [Сделать шаг]
let doStep (b : Board) (step : Step) =
  let num : int = getN b step  
  let rec f (b : Board) (s : Step) (g : Side) (n : int) =
      match n with
      | c when c = MINDIFF -> None
      | 0 -> None
      | 1 -> if (s.side = g) && (isEmpty b s) then
                takeEnemyScore b s
             else
                setInc b s
      | a -> f (setInc b s) (next s) g (a-1) 
  f (setZero b step) (next step) step.side num
let CheckStep (b : Board) (s : Step) =
  match b with
    | None -> false
    | _ -> let num : int = getN b s
           let dist : int = (num - (Kalah - s.row)) % 13
           match dist with
            | 0 -> true
            | c -> false
            // ---------------    Ход компьютера     -----------------
let rec ComputerStep (b : Board) (gamer : Side) =
  printBoard b 
  printfn "Computer`s step." 
  let calcdiff (b : Board) (s : Step)  =
    match b with
      | None -> MINDIFF
      | _ -> (getN b (gKalah s)) - (getN b (difSideStep (gKalah s)))
  
  // Последний уровень глубины
  let rec funcLast (b : Board) (s : Step) (lvl : int) =
    match b with
      | None -> None
      | _ ->    // Проверка на Дополнительный ход
                let b1 = match CheckStep b s  with
                           | true  -> funcLast (doStep b s) (mStep s.side 0) (lvl-1)
                           | false -> doStep b s
                if s.row = 5 then
                  b1
                else
                  let b2 = funcLast b (next s) (lvl-1)
                  if s.row = 0 && (b1 = None) && (b2 = None) then
                    toWinBoard b s.side
                  else
                    match calcdiff b1 s  > calcdiff b2 s with
                     | true -> b1
                     | false -> b2
  // первый уровень глубины
  let rec funcFirst (b : Board) (s : Step) = 
    let bfrom = match CheckStep b s with
                  | true  -> funcLast (doStep b s) (mStep s.side 0) (DEFAULTLVL)
                  | false -> doStep b s
    let b1 = funcLast bfrom (mStep (difSide s.side) 0) DEFAULTLVL
    if (s.row = 5) then
      s, ( calcdiff b1 s )
    else 
      let stepInt : StepInt = funcFirst b (next s) 
      let diff = calcdiff bfrom s 
      if s.row = 0 && (snd stepInt = MINDIFF) && (diff = MINDIFF) then
        printfn "We Have Any Troubles" 
        s, (calcdiff (toWinBoard b s.side) s)
      else
        match diff > snd stepInt with
            | true -> s, diff
            | false -> stepInt
            
  let step = fst (funcFirst b (mStep gamer 0))
  if CheckStep b step then 
    ComputerStep (doStep b step) gamer
  else 
    doStep b step
// ---------------    Ход человека     -----------------
let rec HumanStep (b : Board) (g : Side) =
  printfn ""
  printBoard b
  printfn "Your step. Enter the cell (1-6)."
  let input = System.Console.ReadLine() // Считывает следующую строку символов из стандартного входного потока (проверка короче )
  if input.Length <> 1 || input.[0] < '1' || input.[0] > '6' then
    printfn "Illegal input."
    HumanStep b g
  else 
    let step : Step = mStep g (int(input.[0]) - int('1'))
    if (getN b step = 0) then 
      printfn "Empty cell."
      HumanStep b g 
    else 
      if CheckStep b step then
        HumanStep (doStep b step) g 
      else 
        doStep b step
          
let rec gameOn (b : Board) (gamer : Side) =
  if ((isWinBoard b gamer)&&(getN2 b Comp Kalah>getN2 b Hum Kalah)) then
    printBoard (toWinBoard b gamer)
    printfn "Game Over"
    printfn "Computer won"
  else
    if ((isWinBoard b gamer)&&(getN2 b Comp Kalah<getN2 b Hum Kalah)) then
     printBoard (toWinBoard b gamer)
     printfn "Game Over"
     printfn "Human won"
     else
      if (gamer = Hum) then
       gameOn (HumanStep b gamer) (difSide gamer)
      else 
      gameOn (ComputerStep b gamer) (difSide gamer)
[<EntryPoint>]
let main argv = 
    let b = startBoard
    let b = gameOn b Hum
    ignore( System.Console.ReadKey() ) 
    0