(function (Drupal) {
  Drupal.behaviors.agTabs = {
    attach(context) {
      const tabs = context.querySelectorAll('.ag-tabs');
      tabs.forEach((tabBlock) => {
        const buttons = tabBlock.querySelectorAll('.ag-tabs__tab');
        const panels = tabBlock.querySelectorAll('.ag-tabs__panel');
        buttons.forEach((btn, index) => {
          if (btn.dataset.agTabsInit) {
            return;
          }
          btn.dataset.agTabsInit = 'true';
          btn.addEventListener('click', () => {
            panels.forEach((p) => p.hidden = true);
            if (panels[index]) {
              panels[index].hidden = false;
            }
          });
        });
      });
    }
  };
})(Drupal);
