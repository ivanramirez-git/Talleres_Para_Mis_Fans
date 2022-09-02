import 'package:flutter/material.dart';

class SliderScreen extends StatefulWidget {
  const SliderScreen({Key? key}) : super(key: key);

  @override
  State<SliderScreen> createState() => _SliderScreenState();
}

class _SliderScreenState extends State<SliderScreen> {
  double _value = 200;
  bool _isEnabled = true;
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Slider & Checks'),
      ),
      body: Column(
        children: [
          Slider(
            min: 100,
            max: 350,
            value: _value,
            // si es dark mode usar AppTheme.primaryColorDark y si no AppTheme.primaryColor
            activeColor: Theme.of(context).primaryColor,
            onChanged: _isEnabled
                ? (value) {
                    _value = value;
                    debugPrint('$value');
                    setState(() {});
                  }
                : null,
          ),
          // Checkbox(
          //     value: _isEnabled,
          //     onChanged: (value) {
          //       _isEnabled = value ?? true;
          //       setState(() {});
          //     }),
          // Switch(
          //   value: _isEnabled,
          //   onChanged: (value) {
          //     setState(() {
          //       _isEnabled = value;
          //     });
          //   },
          // ),
          CheckboxListTile(
            title: const Text('Habilitar slider'),
            value: _isEnabled,
            activeColor: Theme.of(context).primaryColor,
            onChanged: (value) {
              setState(() {
                _isEnabled = value ?? false;
              });
            },
          ),
          SwitchListTile.adaptive(
            title: const Text('Habilitar slider'),
            value: _isEnabled,
            activeColor: Theme.of(context).primaryColor,
            onChanged: (value) {
              setState(() {
                _isEnabled = value;
              });
            },
          ),
          const AboutListTile(),

          Expanded(
            child: SingleChildScrollView(
              child: Image(
                image: const NetworkImage(
                    'https://www.cryptosisnft.io/images/56-p-500.png'),
                fit: BoxFit.contain,
                width: _value,
              ),
            ),
          ),
        ],
      ),
    );
  }
}
