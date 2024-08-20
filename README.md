# pxemi.7z
Filename-first stack-based programming language Pxem interpreter

Taken from https://web.archive.org/web/20240229104548/https://vivibit.net/remember_pxem/

## How to build
    g++ -o pxemi pxemInterpreter.cpp

or

    clang++ -o pxemi pxemInterpreter.cpp

## Usage
    pxemi FILE

The FILE must name an actual readable file.

## Specs
* Slash and backslash delimit path; only basename considered to be non-comment code.
* Byte-unit string
* C++ int as data type (size depends on your environment, at least 32 bits)
* Overflow, underflow unhandled as is
* File content is null-char-termined
* Loop check is done at runtime, not at compile time
* .p, .o work byte-unit
* .n works as expected
* .i works as byte-unit, -1 as EOF
* ._ works as expected, overflow not considered, non-integer handling unimplemented but pushes zero
* .c to empty stack unimplemented; results in segmentation fault
* .s implemented as is
* .v works as is
* .f works as is
* .e works as is
* .r to empty stack unhandled. .r to value zero results in zero division
* .w, .x, .y, .z works as is. Empty is truthy. Unimplemented for case when falsey and matching .a is missing.
* .a works as is. Unimplemented for case when matching loop beginner is missing.
* .t, .m works as is. Calling .t when empty stack and calling .m when empty register do nothing.
* .d works as is.
* Arithmetic commands to stacks with <2 items do nothing.
* .+, .! work as is. Overflow unhandled as is.
* .- works as is. Overflow unhandled as is.
* .$, .% works as is. Zero-division unhandled.

## TODO
Refactor source code.

## AUTHORS
Copyright (C) 2008 ぬこ

Copyright (C) 2018 nk.

Copyright (C) 2024 Tpaefawzen

## LICENSE
Taken from https://web.archive.org/web/20240229104548/https://vivibit.net/remember_pxem/ :

> nk. より:
> 2020年10月2日 14:58
> いつもありがとうございます。
> 結論から申し上げますと、私が書いたPxemのインタプリタのコードに関して、自由に扱ってくれて構わない（WTFPLライセンス）という認識です。
> 
> こう考えるに至った経緯について記しておきます。
> 当時はライセンスのことなんて全く考えてませんでした。そもそも、こんな風に愛して遊んでくれる人がいるとも思っていませんでした。作ったのが私だとしても、もはやあなたのほうが造詣が深いと言えるでしょう。楽しんでもらえてとてもうれしく思っています。
> 記事で自分の子供のようだとも書きましたが、感覚的には、すでに自分の手元から巣立っているようにも思えます。私が書いたコードは、もはやPxemという言語設計に形を与えただけのものにすぎないというのが現在の認識です。
> というわけで、ライセンスとして付与するならWTFPLになります。良識の範囲内で、好きに遊んでやってください。


