# AG Theme Documentation

## Overview

AG Theme is a custom Drupal CMS / Mercury child theme built for Drupal 10 and Drupal 11. The theme includes a complete component-based structure, Layout Builder layouts, theme settings, dynamic styling, SCSS build tools, PostCSS processing, linting, and formatting support.

Repository:

```text
https://github.com/alok160684/ag_theme
```

Theme machine name:

```text
ag_theme
```

Base theme:

```yaml
base theme: mercury
```

---

## What Was Added in This Theme

### 1. Drupal Theme Core Files

```text
ag_theme.info.yml
ag_theme.libraries.yml
ag_theme.theme
logo.svg
```

Purpose:

- Defines the Drupal theme.
- Uses Mercury as the base theme.
- Registers global CSS, component CSS, and JavaScript libraries.
- Adds preprocess logic for dynamic CSS variables, logo handling, Google Fonts, and theme settings.

---

### 2. Theme Settings UI

Theme settings were added under:

```text
/admin/appearance/settings/ag_theme
```

Files:

```text
includes/theme-settings.inc
config/install/ag_theme.settings.yml
config/schema/ag_theme.settings.schema.yml
```

Settings added:

- Show logo toggle
- Custom logo upload
- Primary color picker
- Secondary color picker
- Layout width dropdown
- Body font family selector
- Heading font family selector
- Base font size selector
- Google Font selector
- Apply Google Font to headings toggle
- Dark mode toggle
- Dark background color
- Dark text color

These settings are used by `ag_theme.theme` to output dynamic CSS variables.

---

### 3. Dynamic CSS Variables

The theme outputs CSS variables from Drupal admin settings.

Example generated variables:

```css
:root {
  --ag-color-primary: #1f4f82;
  --ag-color-secondary: #f5a623;
  --ag-container-width: 1200px;
  --ag-font-family: Arial, Helvetica, sans-serif;
  --ag-heading-font-family: Arial, Helvetica, sans-serif;
  --ag-font-size-base: 16px;
}
```

Use these variables in CSS/SCSS:

```css
body {
  font-family: var(--ag-font-family);
  font-size: var(--ag-font-size-base);
}

.ag-container {
  max-width: var(--ag-container-width);
}

.ag-button {
  background-color: var(--ag-color-primary);
}
```

---

### 4. Logo Support

Default logo:

```text
logo.svg
```

Admin uploaded logo support:

```text
/admin/appearance/settings/ag_theme
```

The theme supports:

- Default root logo fallback
- Uploaded logo override
- Show/hide logo setting

Twig variable examples:

```twig
{% if ag_show_logo %}
  <img src="{{ ag_logo }}" alt="Site logo">
{% endif %}
```

---

### 5. Google Font Integration

Google Font selection was added in Theme Settings.

Available font options:

- Inter
- Roboto
- Open Sans
- Lato
- Montserrat
- Poppins

When selected, the theme injects a Google Fonts stylesheet into the page head.

Example:

```html
<link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;600;700&display=swap">
```

---

### 6. Dark Mode Support

Dark mode settings include:

- Enable dark mode
- Dark background color
- Dark text color

Default values:

```yaml
ag_enable_dark_mode: false
ag_dark_background_color: '#111827'
ag_dark_text_color: '#f9fafb'
```

Recommended CSS pattern:

```css
[data-theme='dark'] {
  background-color: var(--ag-dark-background-color);
  color: var(--ag-dark-text-color);
}
```

---

## Component Library

The theme includes a Mercury-style component architecture.

Component folder:

```text
components/
```

Components added:

```text
components/header/
components/footer/
components/hero/
components/card/
components/grid/
components/section/
components/button/
components/media/
components/text/
components/two-column/
components/container/
components/accordion/
components/tabs/
components/banner/
components/alert/
components/breadcrumb/
components/modal/
```

Each component usually contains:

```text
component-name.twig
component-name.css
```

Example:

```text
components/hero/hero.twig
components/hero/hero.css
components/hero/hero.stories.yml
```

---

## Component Usage Examples

### Hero Component

```twig
{% include '@ag_theme/components/hero/hero.twig' with {
  title: 'Welcome to AG Theme',
  description: 'Mercury child theme hero component.',
  cta: 'Learn more'
} %}
```

### Card Component

```twig
{% include '@ag_theme/components/card/card.twig' with {
  title: 'Card title',
  text: 'This is sample card text.',
  link: 'Read more'
} %}
```

### Alert Component

```twig
{% include '@ag_theme/components/alert/alert.twig' with {
  type: 'success',
  message: 'Saved successfully.'
} %}
```

Supported alert types:

```text
info
success
warning
error
```

---

## Component Stories

Story files were added for component previews/documentation:

```text
components/hero/hero.stories.yml
components/card/card.stories.yml
components/banner/banner.stories.yml
```

These files document sample component data and can be used as a starting point for Storybook or Drupal component preview workflows.

---

## Templates Added

Main templates:

```text
templates/page.html.twig
templates/node.html.twig
templates/block.html.twig
templates/region.html.twig
templates/field.html.twig
templates/menu.html.twig
templates/html.base.twig
```

Layout templates:

```text
templates/layout/page--full.html.twig
templates/layout/page--sidebar.html.twig
templates/layout/page--landing.html.twig
```

Use these templates for:

- Full-width pages
- Sidebar pages
- Landing pages
- Basic Drupal entity rendering

---

## Layout Builder Layouts

Layout Builder layouts were added using:

```text
ag_theme.layouts.yml
```

Layouts added:

```text
AG One column
AG Two column
AG Three column
```

Layout template files:

```text
layouts/one-column/one-column.html.twig
layouts/two-column/two-column.html.twig
layouts/three-column/three-column.html.twig
```

These appear under:

```text
Layout Builder → Add Section → AG Theme
```

---

## JavaScript Behaviors

Drupal behavior-based JavaScript was added for interactive components.

Files:

```text
js/components/accordion.js
js/components/tabs.js
js/components/modal.js
```

Registered in:

```text
ag_theme.libraries.yml
```

Library:

```yaml
component-scripts:
  js:
    js/components/accordion.js: {}
    js/components/tabs.js: {}
    js/components/modal.js: {}
  dependencies:
    - core/drupal
```

---

## SCSS Architecture

SCSS source folder:

```text
scss/
```

Entry file:

```text
scss/theme.scss
```

Structure:

```text
scss/
├── base/
├── layout/
├── components/
├── utilities/
└── theme.scss
```

The compiled output is:

```text
css/style.css
```

---

## Frontend Build System

Files added:

```text
package.json
postcss.config.js
.browserslistrc
.stylelintrc.json
.prettierrc
.prettierignore
.gitignore
README-frontend-build.md
```

Tools included:

- Sass
- PostCSS
- Autoprefixer
- cssnano
- Stylelint
- Prettier

---

## NPM Commands

Install dependencies:

```bash
npm install
```

Build development CSS:

```bash
npm run build:css
```

Build minified production CSS:

```bash
npm run build:css:min
```

Watch SCSS changes:

```bash
npm run watch:css
```

Run CSS/SCSS linting:

```bash
npm run lint:css
```

Auto-fix CSS/SCSS lint issues:

```bash
npm run lint:css:fix
```

Format files:

```bash
npm run format
```

Check formatting:

```bash
npm run format:check
```

---

## How to Install the Theme in Drupal

### Step 1: Place theme in custom themes folder

```text
web/themes/custom/ag_theme
```

### Step 2: Install frontend dependencies

```bash
cd web/themes/custom/ag_theme
npm install
```

### Step 3: Build CSS

```bash
npm run build:css
```

For production:

```bash
npm run build:css:min
```

### Step 4: Enable the theme

```bash
drush theme:enable ag_theme
```

### Step 5: Set as default theme

```bash
drush config:set system.theme default ag_theme -y
```

### Step 6: Clear cache

```bash
drush cr
```

### Step 7: Configure theme settings

Open:

```text
/admin/appearance/settings/ag_theme
```

Configure:

- Logo
- Colors
- Fonts
- Google Font
- Layout width
- Dark mode

---

## How to Use Layout Builder Layouts

1. Enable Layout Builder if not already enabled.
2. Go to a content type display settings page.
3. Enable Layout Builder.
4. Click Manage layout.
5. Click Add section.
6. Choose one of:

```text
AG One column
AG Two column
AG Three column
```

7. Add blocks/components into layout regions.
8. Save layout.

---

## How to Add a New Component

Example: Create a `feature` component.

Create folder:

```text
components/feature/
```

Add Twig:

```text
components/feature/feature.twig
```

Add CSS:

```text
components/feature/feature.css
```

Register CSS in:

```text
ag_theme.libraries.yml
```

Example:

```yaml
components:
  css:
    component:
      components/feature/feature.css: {}
```

Use in Twig:

```twig
{% include '@ag_theme/components/feature/feature.twig' with {
  title: 'Feature title',
  text: 'Feature text'
} %}
```

---

## How to Add SCSS for a New Component

Create file:

```text
scss/components/_feature.scss
```

Import it in:

```text
scss/theme.scss
```

Example:

```scss
@use 'components/feature';
```

Build CSS:

```bash
npm run build:css
```

---

## Recommended Development Workflow

During development:

```bash
npm run watch:css
```

Before commit:

```bash
npm run lint:css
npm run format:check
npm run build:css:min
```

After pulling changes:

```bash
npm install
npm run build:css
drush cr
```

---

## Troubleshooting

### Theme does not appear in Drupal

Check:

```bash
drush theme:list
```

Then clear cache:

```bash
drush cr
```

Make sure the theme is located at:

```text
web/themes/custom/ag_theme
```

### Styles are not loading

Run:

```bash
npm run build:css
drush cr
```

Check `ag_theme.libraries.yml` contains:

```yaml
global-styling:
  css:
    theme:
      css/style.css: {}
```

### Layouts do not appear in Layout Builder

Check:

```text
ag_theme.layouts.yml
```

Then clear cache:

```bash
drush cr
```

### Google Font is not loading

Check theme settings:

```text
/admin/appearance/settings/ag_theme
```

Select a Google Font and save configuration.

Then clear cache:

```bash
drush cr
```

### Uploaded logo is not showing

Check:

- Show logo is enabled.
- Logo file uploaded successfully.
- Public files directory is writable.
- Cache is cleared.

---

## Supporting References

Use these references when more detail is needed.

### Drupal Theme Development

- Drupal Theme API: https://www.drupal.org/docs/develop/theming-drupal
- Drupal theme .info.yml files: https://www.drupal.org/docs/develop/theming-drupal/defining-a-theme-with-an-infoyml-file
- Drupal libraries API: https://www.drupal.org/docs/develop/creating-modules/adding-assets-css-js-to-a-drupal-module-via-librariesyml
- Drupal Twig templates: https://www.drupal.org/docs/develop/theming-drupal/twig-in-drupal

### Drupal Layout Builder

- Layout Builder overview: https://www.drupal.org/docs/8/core/modules/layout-builder
- Creating custom layouts: https://www.drupal.org/docs/drupal-apis/layout-api/how-to-register-layouts

### Drupal Configuration and Theme Settings

- Configuration API: https://www.drupal.org/docs/drupal-apis/configuration-api
- Theme settings: https://www.drupal.org/docs/develop/theming-drupal/theme-settings

### Frontend Build Tools

- Sass documentation: https://sass-lang.com/documentation/
- PostCSS: https://postcss.org/
- Autoprefixer: https://github.com/postcss/autoprefixer
- cssnano: https://cssnano.github.io/cssnano/
- Stylelint: https://stylelint.io/
- Prettier: https://prettier.io/
- Browserslist: https://github.com/browserslist/browserslist

### Google Fonts

- Google Fonts: https://fonts.google.com/
- Google Fonts CSS API: https://developers.google.com/fonts/docs/css2

---

## Final Summary

AG Theme now includes:

- Mercury child theme setup
- Drupal 10/11 compatibility
- Component-based architecture
- Layout Builder layouts
- Theme settings UI
- Dynamic colors and typography
- Logo upload support
- Google Font integration
- Dark mode foundation
- SCSS architecture
- Sass compiler
- PostCSS and Autoprefixer
- cssnano production optimization
- Stylelint linting
- Prettier formatting

This theme is now a strong foundation for a production-ready Drupal CMS / Mercury-based frontend system.
